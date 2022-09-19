#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll T;

void MAIN(){
	ll n, x;
	cin >> x;
	str s;
	cin >> s;
	n = s.size();
	str t = s;
	ll len = n;
	for(int l = 0; l < x; l++){
		len += (s[l] - '1') * (len - l - 1);
		len %= Mod;
		if(s.size() >= x + 2) continue;
		else {
			if(s[l] == '1') continue;
			t = s.substr(l + 1, s.size());
			for(int j = 1; j < (s[l]-'0'); j++){
				s += t;
			}
		}
	}
	cout << (len + Mod) % Mod << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) MAIN();
	return 0;
}