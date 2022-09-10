#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long long ll;

int fi(int a)
{
	int b=a;
	int fii=1;
	for(int i=2;i*i<=b;i++)
	{
		if(a%i==0)
		{
			a/=i;
			fii*=i-1;
		}
		while(a%i==0)
		{
			a/=i;
			fii*=i;
		}
			
	}
	if(a>1)
		return fii*(a-1);
	return fii;
	
}

LL pot(LL a,LL w,LL mod)
{
	if(w==0)	
		return 1;
	LL b=pot(a,w/2,mod);
	b*=b;
	b%=mod;
	if(w%2==1)
	{
		b*=a;
		b%=mod;
	}
	return b;
}

int rzad(int a,int q)
{
	int ord=fi(q);
	
	int res=ord;
	int morda=ord;
	int orda=ord;
	for(int i=1;i*i<=orda;i++)
	{
		if(ord%i==0)
		{
			if(pot(a,ord/i,q)==1)
				res=min(res,ord/i);
			if(pot(a,i,q)==1)
				res=min(res,i);
		}		
	}
	return res;
	
}

const int MAX_N=1e6+200;
ll n,m,a,Q,P;
ll rev(ll a)
{
	return pot(a,P-2,P);
}
ll sil[MAX_N];
ll sym[MAX_N], pref[MAX_N];

int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&a,&Q);
	P=rzad(a,Q);
	sil[0]=1;
	for(ll i=1; i<MAX_N; ++i) sil[i]=(sil[i-1]*i)%P;		
	for(ll i=0; i<=m; ++i)
	{
		sym[i]=sil[m]*rev(sil[m-i]); sym[i]%=P;
		sym[i]*=rev(sil[i]); sym[i]%=P;
		if(i!=0) pref[i]=pref[i-1];
		pref[i]+=sym[i]; pref[i]%=P;
		//printf("%lld ",sym[i]);
	}
//	printf("\n");
	for(int j=n; j>=1; --j)
	{
//		printf("%lld ",pref[j]);
		printf("%lld ",pot(a,pref[min(m,(LL)j-1)],Q));
	}
	printf("\n");
	return 0;
}