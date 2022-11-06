#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db long double
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline int rd()
{
	int x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=8005;
int n,nn,ql,qr,e[N][N],d[N],q[N],o[N],c[N];char s[N];ll ans;
int main()
{
	n=rd();nn=n;
	rep(i,1,n)
	{
		scanf("%s",s+1);
		rep(j,1,n/4)
		{
			int x=isdigit(s[j])?s[j]-'0':10+s[j]-'A';
			rep0(k,0,4)e[i][4*j-k]=x>>k&1;
		}
	}
	rep(i,1,n)rep(j,1,n)if(e[i][j])d[j]++;
	rep(i,1,n)if(!d[i])q[++qr]=i;
	while(ql<qr)
	{
		int x=q[++ql];o[x]=3;nn--;ans+=(614ll*n+1)*nn;
		rep(i,1,n)if(e[x][i]&&!--d[i])q[++qr]=i;
	} 
	if(!nn){printf("%lld\n",ans);return 0;}
	int x=0;rep(i,1,n)if(d[i]>d[x])x=i;
	rep(i,1,n)if(o[i]!=3)o[i]=e[i][x]||i==x?1:2;
	rep(i,1,n)if(o[i]!=3)rep(j,1,n)if(o[j]!=3&&o[i]!=o[j]&&e[i][j])c[j]++;
	rep(i,1,n)if(o[i]!=3)rep(j,i+1,n)if(o[j]!=3)ans+=3+(o[i]==o[j]&&c[i]==c[j]);
	printf("%lld\n",ans);return 0;
}