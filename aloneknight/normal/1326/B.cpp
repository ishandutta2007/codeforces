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
int n;ll mx;
int main()
{
	scanf("%d",&n);mx=0;
	for(int i=1;i<=n;i++)
	{
		ll x;scanf("%lld",&x);
		ll y=mx+x;
		printf("%lld ",y);
		mx=max(mx,y);
	}
	return 0;
}