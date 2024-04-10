#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n;
map<ll , ll> mp;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		mp.clear();
		cin >> n; ll ans = 0;
		for(int i = 1 ; i <= n ; i++){
			ll x; cin >> x;
			ans += mp[x] * (n - i + 1);
			mp[x] += i;
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/