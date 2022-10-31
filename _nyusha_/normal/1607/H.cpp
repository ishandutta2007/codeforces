#include<bits/stdc++.h>

using namespace std;

struct pt {
    int a, b, m, i;
};

int const maxn = 2e5 + 5;

map < int, vector < pt > > t;
pair < int, int > ans[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b, m;
        cin >> n;
        t.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a >> b >> m;
            t[a + b - m].push_back({a, b, m, i});
        }
        int answ = 0;
        for (auto key : t) {
            vector < pt > now = key.second;
            sort(now.begin(), now.end(), [](pt s, pt f) {
                return s.a - max(0, s.m - s.b) < f.a - max(0, f.m - f.b);
            });
            set < int > used;
            for (auto key : now) {
                auto L = used.lower_bound(key.a - key.m);
                auto R = used.upper_bound(key.a - max((key.m - key.b), 0));
                if (L == R) {
                    used.insert(key.a - max((key.m - key.b), 0));
                    ans[key.i] = {max((key.m - key.b), 0), key.m - max((key.m - key.b), 0)};
                    answ++;
                } else {
                    ans[key.i] = {key.a - (*L), key.m - (key.a - (*L))};
                }
            }
        }
        cout << answ << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << ans[i].first << " " << ans[i].second << '\n';
        }
    }
    return 0;
}