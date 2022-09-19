// That's How much we have in common
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

int Main(){
	ll n, k;
	cin >> n >> k;
	str s;
	cin >> s;
	for(int i = n - 1; i >= 0; i--){
		if(i + k >= n) continue;
		if(s[i] == '?'){
			s[i] = s[i + k];
			continue;
		}
		if(s[i + k] == '?') continue;
		if(s[i] != s[i + k]) return 0;
	}
	int c0 = 0, c1 = 0;
	for(int i = 0; i < k; i++) if(s[i] == '0') c0 ++;
	for(int i = 0; i < k; i++) if(s[i] == '1') c1 ++;
	int mx = max(c0, c1);
	if(mx + mx <= k) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) cout << (Main() ? "YES\n" : "NO\n");
	return 0;
}