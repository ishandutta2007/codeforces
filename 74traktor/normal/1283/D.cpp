#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
set < int > used;
int const maxn = 2e5 + 5;
int dels[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x;
    ll ans = 0;
    cin >> n >> m;
    set < int > T;
    vector < int > out;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        T.insert(x);
        used.insert(x);
    }
    int ptr = 1;
    for (int dist = 1; ptr <= m; ++dist) {
        int cur = 1;
        for (auto p : T) {
            int start = ptr;
            if (used.find(p - dist) == used.end() && ptr <= m) {
                used.insert(p - dist);
                ans += (ll)dist;
                out.push_back(p - dist);
                ptr++;
            }
            if (used.find(p + dist) == used.end() && ptr <= m) {
                used.insert(p + dist);
                ans += (ll)dist;
                out.push_back(p + dist);
                ptr++;
            }
            if (start == ptr) {
                dels[cur++] = p;
            }
        }
        for (int j = 1; j < cur; ++j) T.erase(dels[j]);
    }
    cout << ans << '\n';
    for (auto key : out) cout << key << " ";
    return 0;
}