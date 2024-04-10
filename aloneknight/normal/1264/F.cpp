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
const int m=1e9;
const ll M=1000000000000000000ll;
int main()
{
//	int a=0,b=1,T=7e9;
//	rep(i,1,T){int c=b;b=(a+b)%m;a=c;if(a==0&&b==1){cout<<i<<endl;break;}}
//	n=1500000000
//	a=168354898000000000 b=584177449000000001	
//	int t=584177449;
//	rep(i,1,m)if(1ll*i*t%m==1){cout<<i<<endl;break;}
//	t=584177449 t^-1=614945049
	int iv=614945049,n=1500000000;
	int t=rd(),a=rd(),d=rd();
	ll b=1ll*(1ll*a*iv%m)*n+1;
	ll e=1ll*(1ll*d*iv%m)*n;
	printf("%lld %lld\n",b,e);
	return 0;
}