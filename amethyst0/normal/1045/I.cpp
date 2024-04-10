#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sigma = 26;

map<int, int> cnt;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < sz(s); ++i) {
            mask ^= (1 << (s[i] - 'a'));
        }
        ++cnt[mask];
    }

    ll ans = 0;
    for (auto it : cnt) {
        int mask = it.first;
        /*if (!cnt[mask]) {
            continue;
        }*/
        ans += ll(it.second) * (it.second - 1);
        for (int i = 0; i < sigma; ++i) {
            int nx = (mask ^ (1 << i));
            if (!cnt.count(nx)) {
                continue;
            }
            ans += ll(it.second) * cnt[nx];
        }
    }

    //cout << ans << "\n";
    cout << ans / 2 << "\n";

}