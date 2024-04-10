#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=105;

ll n;
ll work1(ll t,int cnt)
{
	if(!cnt)return 0;
	ll u=(t>>(2*cnt-2));
	if(u==0)return work1(t,cnt-1);
	if(u==1)return (2ll<<(2*cnt-2))+work1(t-(1ll<<(2*cnt-2)),cnt-1);
	if(u==2)return (3ll<<(2*cnt-2))+work1(t-(2ll<<(2*cnt-2)),cnt-1);
	if(u==3)return (1ll<<(2*cnt-2))+work1(t-(3ll<<(2*cnt-2)),cnt-1);
}
ll work2(ll t,int cnt)
{
	if(!cnt)return 0;
	ll u=(t>>(2*cnt-2));
	if(u==0)return work2(t,cnt-1);
	if(u==1)return (3ll<<(2*cnt-2))+work2(t-(1ll<<(2*cnt-2)),cnt-1);
	if(u==2)return (1ll<<(2*cnt-2))+work2(t-(2ll<<(2*cnt-2)),cnt-1);
	if(u==3)return (2ll<<(2*cnt-2))+work2(t-(3ll<<(2*cnt-2)),cnt-1);
}
ll work(ll n)
{
	int cnt=0;
	for(ll x=n;x;x>>=2)++cnt;
	ll t=(n-(1ll<<(2*cnt-2)))/3;
	if(n%3==1)return (1ll<<(2*cnt-2))+t;
	if(n%3==2)return (2ll<<(2*cnt-2))+work1(t,cnt-1);
	if(n%3==0)return (3ll<<(2*cnt-2))+work2(t,cnt-1);
}
void solve()
{
	readint(n);
	printf("%lld\n",work(n));
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}