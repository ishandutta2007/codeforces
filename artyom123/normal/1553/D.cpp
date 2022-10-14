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
        int n = s.size();
        bool ok = 0;
        for (int k = 0; k < 2; k++) {
            int kek = k + t.size() - 1;
            if (kek % 2 == n % 2) continue;
            int j = 0;
            for (int i = 0; i < n && j < (int)t.size(); i++) {
                if (i % 2 == (k + j) % 2 && s[i] == t[j]) j++;
            }
            if ((int)t.size() == j) ok = 1;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}