#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
const int N=2000005,P=998244353;
int n,m,l,f[N],p[N],f2[N];char s[N];
inline int gt1(int l,int r){return (f[r]+1ll*f[l-1]*(P-p[r-l+1]))%P;}
inline int gt2(int l,int r){return (f2[l]+1ll*f2[r+1]*(P-p[r-l+1]))%P;}
inline void sol()
{
	scanf("%s",s+1);n=strlen(s+1);int ff=0;
	rep(i,1,n)if(s[i]!=s[n+1-i]){ff=i;break;}
	if(!ff)
	{
		rep(i,1,n)putchar(s[i]);
		putchar('\n');return;
	}
	f[0]=f2[n+1]=0;
	p[0]=1;rep(i,1,n)p[i]=233ll*p[i-1]%P;
	rep(i,1,n)f[i]=(233ll*f[i-1]+s[i])%P;
	per(i,n,1)f2[i]=(233ll*f2[i+1]+s[i])%P;
	int l=ff,r=n-ff+1;
	int L=n-ff+2,R=ff-1;
	for(int i=l+1;i<=r;i+=2)
	{
		int m=(i+l-1)/2;
		if(gt2(l,m)==gt1(m+1,i))R=max(R,i);
	}
	for(int i=l;i<=r;i+=2)
	{
		int m=(i+l)/2;
		if(gt2(l,m)==gt1(m,i))R=max(R,i);
	}
	int t1=R+ff-1;
	for(int i=r-1;i>=l;i-=2)
	{
		int m=(i+r-1)/2;
		if(gt2(i,m)==gt1(m+1,r))L=min(L,i);
	}
	for(int i=r;i>=l;i-=2)
	{
		int m=(i+r)/2;
		if(gt2(i,m)==gt1(m,r))L=min(L,i);
	}
	int t2=n-L+1+ff-1;
	if(t1>=t2)
	{
		for(int i=1;i<=R;i++)putchar(s[i]);
		for(int i=r+1;i<=n;i++)putchar(s[i]);
		putchar('\n');return;
	}
	for(int i=1;i<l;i++)putchar(s[i]);
	for(int i=L;i<=n;i++)putchar(s[i]);
	putchar('\n');return;
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)sol();return 0;
}