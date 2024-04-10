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

ll n , ans , x[26] , ps[MAXN];
string s;
map<ll , int> cnt[26];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 0 ; i < 26 ; i++)	cin >> x[i];
	cin >> s; n = SZ(s);
	s = "." + s;
	for(int i = 1 ; i <= n ; i++){
		ps[i] = (ps[i - 1] + x[s[i] - 97]);
		ans += cnt[s[i] - 97][ps[i - 1]];
		cnt[s[i] - 97][ps[i]]++;
	}
	cout << ans << endl;

    return 0;
}
/*

*/