#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<ll> v;
bitset<100000> used;

int main()
{jizz
	ll a,b,x;
	cin >> a >> b;
	for(x=1;x*(x+1)/2<=a+b;++x);
	--x;
	for(ll i=x;i>0&&a;--i)
		if(a>=i) a-=i,v.pb(i),used[i]=1;
	cout << v.size() << "\n";
	for(int i:v)
		cout << i << " ";
	ET;
	cout << x-v.size() << "\n";
	for(int i=1;i<=x;++i)
		if(!used[i]) cout << i << " ";
	ET;
}