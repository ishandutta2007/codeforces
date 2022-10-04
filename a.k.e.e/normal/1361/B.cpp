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
const int MAXN=1000005,MOD=1000000007;
const ll LIM=1ll<<60;

int n;
ll p,a[MAXN];
struct Int
{
	ll x,y,z;
	Int(){}
	Int(ll t){x=t,y=t%MOD,z=t%2;}
	Int(ll x,ll y,ll z):x(x),y(y),z(z){}
	Int operator *(const Int &b)const
	{
		ll tx=(x>=LIM/b.x?LIM:x*b.x);
		return Int(tx,y*b.y%MOD,z*b.z%2);
	}
	Int operator -(int b)const{return Int(x-b,(y-b+MOD)%MOD,(z+b)%2);}
};
Int qmi(Int x,int y)
{
	Int res(1);
	for(;y;y>>=1,x=x*x)
		if(y&1)res=res*x;
	return res;
}
void solve()
{
	readint(n),readint(p);
	for(int i=1;i<=n;++i)readint(a[i]);
	sort(a+1,a+n+1);
	if(p==1)printf("%d\n",n%2);
	else
	{
		Int cur(1);
		for(int i=n-1;i;--i)
		{
			if(a[i]<a[i+1])cur=cur*qmi(p,a[i+1]-a[i]);
			if(cur.x>0)cur=cur-1;
			else cur=1;
		}
		cur=cur*qmi(p,a[1]);
		printf("%I64d\n",cur.y);
	}
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