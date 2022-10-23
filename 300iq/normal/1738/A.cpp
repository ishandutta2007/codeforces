#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

mt19937 rnd(228);

const int inf = 1e9;

typedef long long ll;

set <int> q[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll sum = 0;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector <int> b(n);
        vector <int> l, r;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (a[i] == 0) {
                l.push_back(b[i]);
            } else {
                r.push_back(b[i]);
            }
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        vector <int> g[2];
        for (int it = 0; it < 2; it++) {
            g[0] = l, g[1] = r;
            int start = it;
            int last = -1;
            ll here = 0;
            for (int z = 0; z < n; z++) {
                if (g[start].empty()) start ^= 1;
                int val = g[start].back();
                if (z == 0) val = g[start][0];
                if (last != start && last != -1) {
                    here += 2 * val;
                } else {
                    here += val;
                }
                last = start;
                if (z == 0) g[start].erase(g[start].begin());
                else g[start].pop_back();
                start ^= 1;
            }
            sum = max(sum, here);
        }
        cout << sum << '\n';
    }
}