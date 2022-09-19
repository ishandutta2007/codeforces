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

pll a[N];

set<pll> st;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	if(n & 1) return cout << "NO\n", 0;
	for(int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
	ll m = n/2;
	for(int i = 0; i + m < n; i++){
		st.insert({a[i].F + a[i + m].F, a[i].S + a[i + m].S});
	}
	if(st.size() == 1) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}