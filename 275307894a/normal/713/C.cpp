#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=1e6+5,M=5e3+5,K=10000+5,mod=998244353,Mod=mod-1;const db eps=1e-5;
int n,x;multiset<int> F;ll ToT;
int main(){
//	freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&x),x-=i,!F.empty()&&(F.erase(--F.end()),0),F.insert(x),F.insert(x),ToT+=x+n;
	int Lp=-n;for(i=n;i;i--) ToT-=1ll*i*(*F.begin()-Lp),Lp=*F.begin(),F.erase(F.begin());printf("%lld\n",ToT);
}