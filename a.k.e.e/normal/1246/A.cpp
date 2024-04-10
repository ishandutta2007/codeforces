#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define k first
#define b second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(register int i=(x);i<=(y);++i)
#define try(i,x,y) for(register int i=(x);i>=(y);--i)
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005,MOD=1000000007;

ll n,p;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	readint(n);readint(p);
	for(int i=0;;++i)
	{
		ll k=n-i*p;
		if(k<i)break;
		int cnt=0;
		enum(i,0,60)if(k&(1ll<<i))++cnt;
		if(cnt<=i)return 0*printf("%d\n",i);
	}
	printf("-1\n");
    return 0;
}