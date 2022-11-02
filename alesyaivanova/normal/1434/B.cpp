#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
pii a[maxn];
int t[maxn];
int q[maxn];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    set<int> pos;
    for (int i = 0; i < 2 * n; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            a[i].ff = 1;
            pos.insert(i);
        } else {
            a[i].ff = -1;
            cin >> a[i].ss;
            t[a[i].ss] = i;
        }
    }
    for (int elem = 1; elem <= n; ++elem) {
        int cur_pos = t[elem];
        auto j = pos.lower_bound(cur_pos);
        if (j == pos.begin()) {
            cout << "NO";
            return 0;
        }
        --j;
        q[*j] = elem;
        pos.erase(j);
    }
    set<int> kek;
    for (int i = 0; i < 2 * n; ++i) {
        if (a[i].ff == 1) {
            kek.insert(q[i]);
        } else {
            if (kek.empty() || (*kek.begin()) != a[i].ss) {
                cout << "NO";
                return 0;
            }
            kek.erase(kek.begin());
        }
    }
    cout << "YES\n";
    for (int i = 0; i < 2 * n; ++i) {
        if (a[i].ff == 1)
            cout << q[i] << " ";
    }
}