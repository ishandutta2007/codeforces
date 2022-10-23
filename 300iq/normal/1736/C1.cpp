#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>

#define x _x
#define y _y

using namespace std;

mt19937 rnd(228);

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) a[i]--;
        for (int i = 0; i < n; i++) {
            a[i] = i - a[i];
        }
        vector <int> br(n + 1, n);

        ll ans = 0;
        set <pair <int, int> > q;
        set <int> ids;
        for (int i = 0; i < n; i++) {
            q.insert({a[i], i});
            ids.insert(i);
        }
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.begin()->first <= i) {
                ids.erase(q.begin()->second);
                q.erase(q.begin());
            }
            auto it = ids.lower_bound(i);
            if (it == ids.end()) ans += n - i;
            else ans += *it - i;
        }

        cout << ans << endl;
    }
}