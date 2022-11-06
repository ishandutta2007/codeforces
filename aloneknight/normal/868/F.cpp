#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int> 
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
#define ls ch[x][0]
#define rs ch[x][1]
inline ll rd()
{
	ll x=0,w=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*w;
}
const int N=200005;
const ll inf=1ll*N*N*N;
int n,k,l,r,a[N],s[N];ll res,f[25][N];
void mov(int tl,int tr)
{
	while(l>tl)res+=s[a[--l]]++;
	while(r<tr)res+=s[a[++r]]++;
	while(l<tl)res-=--s[a[l++]];
	while(r>tr)res-=--s[a[r--]];
}
void sol(int k,int l,int r,int tl,int tr)
{
	if(l>r)return;
	int m=l+r>>1,p=tl;f[k][m]=inf;
	rep(i,tl,min(m,tr))
	{
		mov(i,m);ll w=f[k-1][i-1]+res;
		if(f[k][m]>w)f[k][m]=w,p=i;
	}
	sol(k,l,m-1,tl,p);sol(k,m+1,r,p,tr);
}
int main()
{
	n=rd();k=rd();rep(i,1,n)a[i]=rd();
	rep(i,1,n)res+=s[a[i]]++,f[1][i]=res;
	l=1;r=0;res=0;memset(s,0,sizeof(s));
	rep(i,2,k)sol(i,1,n,1,n);
	printf("%lld\n",f[k][n]);return 0;
}