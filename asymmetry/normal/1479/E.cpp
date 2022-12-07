//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

#define M 1010
#define N 81 * 1000

mt19937_64 rng;
int ran(int a, int b)
{
	return uniform_int_distribution<int>(a,b)(rng);
}

constexpr ull mod=998244353;
int n, m, omi, eno;
int t[M];
ull odp, nomi, deno;
ull sil[N];
ull rev[N];

ull pot(ull a, ull b)
{
	ull k=1;
	while(b)
	{
		if(b&1) k=k*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return k;
}

ull obr(ull a)
{
	ull ret=1;
	int b=mod-2;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

vector<ull> ntt_roots;
void get_roots(int n)
{
	if(n<(int)ntt_roots.size()) return;
	ntt_roots.resize(n);
	ntt_roots[0]=1;
	ntt_roots[1]=pot(5, (mod-1)/n);
	for(int i=2; i<n; ++i)
	{
		ntt_roots[i]=ntt_roots[i-1]*ntt_roots[1]%mod;
	}
}

void ntt(vector<ull> &t)
{
	int n=t.size();
	vector<int> poz(n, 0);
	for(int i=1; i<n; ++i)
	{
		poz[i]=poz[i&(i-1)]+n/(-i&i)/2;
		if(poz[i]<i) swap(t[i], t[poz[i]]);
	}
	get_roots(n);
	int rot=ntt_roots.size();
	for(int i=1; i<n; i<<=1)
	{
		rot>>=1;
		for(int j=0; j<n; j+=(i<<1))
		{
			for(int k=0; k<i; ++k)
			{
				ull val=t[i+j+k]*ntt_roots[k*rot]%mod;
				t[i+j+k]=t[j+k]-val;
				t[j+k]+=val;
				if(t[i+j+k]>mod) t[i+j+k]+=mod;
				if(t[j+k]>=mod) t[j+k]-=mod;
			}
		}
	}
}

void intt(vector<ull> &t)
{
	ntt(t);
	reverse(t.begin()+1, t.end());
	ull w=obr(t.size());
	for(ull &i:t) i=i*w%mod;
}

vector<ull> multiply(vector<ull> a, vector<ull> b)
{
	if((int)min(a.size(), b.size())<=180)
	{
		int n=a.size();
		int m=b.size();
		if(n>m)
		{
			swap(n, m);
			swap(a, b);
		}
		vector<ull> ret(n+m, 0);
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<m; ++j)
			{
				ret[i+j]+=a[i]*b[j];
				ret[i+j]%=mod;
			}
		}
		return ret;
	}
	int n=1;
	while(n<(int)a.size()+(int)b.size()) n<<=1;
	a.resize(n);
	b.resize(n);
	ntt(a);
	ntt(b);
	for(int i=0; i<n; ++i) a[i]=a[i]*b[i]%mod;
	intt(a);
	return a;
}

void shift(vector<ull> &t, int n, int x)
{
	vector<ull> t1(n+1, 0), t2((n<<1)+1, 0), t3;
	for(int i=0; i<=n; ++i)
	{
		if((n-i)&1) t1[i]=rev[i]*rev[n-i]%mod*(mod-t[i])%mod;
		else t1[i]=rev[i]*rev[n-i]%mod*t[i]%mod;
	}
	for(int i=0; i<=n<<1; ++i)
	{
		t2[i]=rev[x+i-n]*sil[x+i-n-1]%mod;
	}
	t3=multiply(t1, t2);
	for(int i=0; i<=n; ++i)
	{
		t[i]=sil[i+x]*rev[i+x-n-1]%mod*t3[n+i]%mod;
	}
}

void ari_shift(vector<ull> &t, int n, int step, int x)
{
	shift(t, n, x/step);
}

ull ilo(ull a, ull b)
{
	ull ret=1;
	if(b-a<100)
	{
		for(ull i=a; i<=b; ++i)
		{
			ret=ret*i%mod;
		}
		return ret;
	}
	int n=1;
	while((ull)n*n<=b-a+1)
	{
		n<<=1;
	}
	vector<ull> t1(n*8+10), t2(n+10), t3(n+10), t4(n+10);
	t1[0]=a*(a+1)%mod;
	t1[1]=(a+2)*(a+3)%mod;
	t1[2]=(a+4)*(a+5)%mod;
	for(int i=2; i<n; i<<=1)
	{
		if((b-a+i*(i+1))/(i*(i+1))<=11)
		{
			int g=(b-a+i*(i+1))/(i*(i+1));
			int l=i;
			for(int k=1; k<g; ++k)
			{
				t2=t1;
				ari_shift(t2, i, i, i*(i+1)*k);
				for(int j=0; j<=i; ++j)
				{
					t1[++l]=t2[j];
				}
			}
			n=i;
			break;
		}
		t4=t3=t2=t1;
		ari_shift(t2, i, i, i*(i+1));
		ari_shift(t3, i, i, i*(i+1)*2);
		ari_shift(t4, i, i, i*(i+1)*3);
		int l=0;
		for(int j=0; j<i; j+=2)
		{
			t1[l++]=t1[j]*t1[j+1]%mod;
		}
		t1[l++]=t1[i]*t2[0]%mod;
		for(int j=1; j<=i; j+=2)
		{
			t1[l++]=t2[j]*t2[j+1]%mod;
		}
		for(int j=0; j<i; j+=2)
		{
			t1[l++]=t3[j]*t3[j+1]%mod;
		}
		t1[l++]=t3[i]*t4[0]%mod;
		for(int j=1; j<=i; j+=2)
		{
			t1[l++]=t4[j]*t4[j+1]%mod;
		}
	}
	ull g=a-1, h=0;
	while(g+n<=b)
	{
		ret=ret*t1[h]%mod;
		++h;
		g+=n;
	}
	for(ull i=g+1; i<=b; ++i) ret=ret*i%mod;
	return ret;
}

ull f(ull a)
{
	nomi=nomi*ilo(2*n-a, omi)%mod;
	omi=2*n-a-1;
	deno=deno*ilo(n-a+1, eno)%mod;
	eno=n-a;
	return (mod-2)*n%mod*obr(n-1)%mod*(nomi*obr(deno)%mod-1+mod)%mod;
}

int main()
{
	sil[0]=1;
	for(int i=1; i<N; ++i)
	{
		sil[i]=sil[i-1]*i%mod;
	}
	rev[N-1]=obr(sil[N-1]);
	for(int i=N-2; ~i; --i)
	{
		rev[i]=rev[i+1]*(i+1)%mod;
	}
	scanf("%d", &m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", &t[i]);
		n+=t[i];
	}
	omi=2*n-1;
	eno=n;
	nomi=deno=1;
	sort(t+1, t+1+m);
	for(int i=1; i<=m; ++i) odp=(odp+f(t[i]))%mod;
	odp=odp+mod-f(n);
	odp%=mod;
	printf("%llu\n", odp);
	return 0;
}