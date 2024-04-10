// Null
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n;
str a, b;
vector<ll> V;

int dp[N];
ll s = 0;


void Main(){
	ll n;
	cin >> n;
	ll mx = 0, v;
	V.clear();
	for(int i = 0; i < n + n; i++){
		cin >> v;
		if(v > mx){
			mx = v;
			V.pb(i);
		}
	}
	V.pb(n + n);
	fill(dp, dp + n + 1, 0);
	dp[0] = 1;
	s = 0;
	ll bl;
	for(int i = 0; i + 1 < V.size(); i++){
		bl = V[i + 1] - V[i];
		for(int j = s; j >= 0; j--) dp[j + bl] |= dp[j];
		s += bl;
	}
	cout << (dp[n] ? "YES\n" : "NO\n");
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}