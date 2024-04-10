#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll f(ll x)
{
	ll re=0;
	while(x) re+=x%10,x/=10;
	return re;
}

int main()
{jizz
	ll a=0,n,x=1,t=1;
	cin >> n;
	while(a*10+9<=n) a=a*10+9,x*=10;
	while(x*t+a<=n) ++t;
	a=a+x*(t-1);
	cout << f(a)+f(n-a) << "\n";
}