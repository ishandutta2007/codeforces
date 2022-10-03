#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;

int Main(){
	cin>>x>>y;
	if (x>y) kill(x*y+y)
	if (y%x==0) kill(x)
	ll z=((y%x))/2;
	ll k=(y-2*z)/x;
	ll n=k*x+z;
	kill(n)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	/*
	for (ll x=2; x<=1000; x+=2) for (ll y=x+2; y<=1000; y+=2){
		ll z=((y%x))/2;
		ll k=(y-2*z)/x;
		ll n=k*x+z;
		if (n%x!=y%n){
			debug2(x, y)
			return 0;
		}
	}
	*/
	
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
1
2

*/