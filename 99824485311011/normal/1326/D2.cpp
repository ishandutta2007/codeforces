#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
typedef unsigned long long ull;
constexpr uint64_t mod = (1ull<<61) - 1;
mt19937 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());
const ull bas=rnd()%10+30;
uint64_t mult(uint64_t a, uint64_t b)
{
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & mod) + (ret>>61);
	ret = (ret & mod) + (ret>>61);
	return ret-1;
}
inline ull add(ull a,ull b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline ull dec(ull a,ull b)
{
	return add(a,mod-b);
}
int T,n;
char s[2000010],is[2000010],t[1000010];
ull pw[2000010],hs[2000010],ihs[2000010];
inline ull gethash(int l,int r,bool iv)
{
	if(l>r)return 0;
	if(iv)
	{
		l=n*2+2-l;r=n*2+2-r;swap(l,r);
		return dec(ihs[r],mult(ihs[l-1],pw[r-l+1]));
	}
	return dec(hs[r],mult(hs[l-1],pw[r-l+1]));
}
void solve()
{
	scanf("%s",t+1);
	n=strlen(t+1);
	for(int i=1;i<=n;i++)
	{
		s[i*2-1]='z'+1;
		s[i*2]=t[i];
	}
	s[n*2+1]='z'+1;
	for(int i=1;i<=n*2+1;i++)hs[i]=add(mult(hs[i-1],bas),s[i]-'a'+1);
	copy(s+1,s+n*2+2,is+1);
	reverse(is+1,is+2*n+2);
	for(int i=1;i<=n*2+1;i++)ihs[i]=add(mult(ihs[i-1],bas),is[i]-'a'+1);
	int ans1=0,ans2=0;
	for(int i=1;i<=n+1;i++)
	{
		int L=1,R=i-1,ret=0;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(gethash(i-mid,i-1,0)==gethash(i+1,i+mid,1))
			{
				ret=mid;
				L=mid+1;
			}
			else R=mid-1;
		}
		if(hs[i-ret-1]==ihs[i-ret-1])
		{
			ans1=max(ans1,i);
		}
	}
	for(int i=n+2;i<=n*2+1;i++)
	{
		int L=1,R=n*2+1-i,ret=0;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(gethash(i-mid,i-1,0)==gethash(i+1,i+mid,1))
			{
				ret=mid;
				L=mid+1;
			}
			else R=mid-1;
		}
		int d=n*2+1-i;
		if(hs[d-ret]==ihs[d-ret])
		{
			ans2=max(ans2,n*2+1-i+1);
		}
	}
	if(ans1>ans2)
	{
		for(int i=1;i<=ans1;i++)if(!(i&1))putchar(s[i]);
		for(int i=ans1-1;i>=1;i--)if(!(i&1))putchar(s[i]);
	}
	else
	{
		for(int i=n*2+1;i>=n*2+1-ans2+1;i--)if(!(i&1))putchar(s[i]);
		for(int i=n*2+1-ans2+2;i<=n*2+1;i++)if(!(i&1))putchar(s[i]);
	}
	puts("");
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=2000000;i++)pw[i]=mult(pw[i-1],bas);
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}