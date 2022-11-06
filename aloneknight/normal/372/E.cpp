#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define db double
#define mp make_pair
#define X first
#define Y second
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<(a).size();++i)
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
#define gc getchar
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=1010,MOD=1e9+7;
int n,tt,ans;
struct P{db x,y;}p[N];
inline bool equ(db x,db y){return abs(x-y)<1e-9;}
struct st{db x,y,k;}V[N*N];
inline bool cmp(st a,st b)
{
	if(!equ(a.x,b.x))return a.x<b.x;
	if(!equ(a.y,b.y))return a.y<b.y;
	return a.k<b.k;
}
int main()
{
	scanf("%d",&n);
	rep(i,1,n)
	{
		db a,b,c,d;scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		db x=a/b,y=c/d;p[i].x=x/(x*x+y*y);p[i].y=y/(x*x+y*y);
	}
	rep(i,1,n)rep(j,i+1,n)
	{
		tt++;V[tt].x=p[i].x+p[j].x;V[tt].y=p[i].y+p[j].y;
		V[tt].k=equ(p[i].x,p[j].x)?1e9:(p[j].y-p[i].y)/(p[j].x-p[i].x);
	}
	sort(V+1,V+tt+1,cmp);
	for(int i=1,j;i<=tt;i=j)
	{
		int c=1,s=1;
		for(j=i+1;j<=tt&&equ(V[j].x,V[i].x)&&equ(V[j].y,V[i].y);j++)
		{
			if(equ(V[j].k,V[j-1].k))c++;else s=1ll*s*(c+1)%MOD,c=1;
		}
		s=1ll*s*(c+1)%MOD;ans=(ans+s-1)%MOD;
	}
	printf("%d\n",(ans+MOD-tt)%MOD);return 0;
}