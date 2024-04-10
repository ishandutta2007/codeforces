#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        string s, t;
        cin >> s >> t;
        bool ok = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            string now = "";
            for (int j = i; j < (int)s.size(); j++) {
                now += s[j];
                string now1 = now;
                for (int k = j - 1; k >= 0 && now1.size() < t.size(); k--) {
                    now1 += s[k];
                }
                if (now1 == t) ok = 1;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}