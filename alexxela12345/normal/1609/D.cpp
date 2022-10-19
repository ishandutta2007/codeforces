#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

const int MAXN = 1e3 + 228;

int pa[MAXN];
int ra[MAXN];

void init() {
    iota(pa, pa + MAXN, 0);
    fill(ra, ra + MAXN, 1);
}

int get(int a) {
    if (pa[a] != a)
        return get(pa[a]);
    return a;
}

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (ra[b] > ra[a])
        swap(a, b);
    ra[a] += ra[b];
    pa[b] = a;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        arr[i].second--;
    }
    init();
    int fr = 0;
    for (auto [a, b] : arr) {
        if (get(a) == get(b)) {
            fr++;
        } else {
            merge(a, b);
        }
        vector<int> comps;
        for (int i = 0; i < n; i++) {
            if (pa[i] == i) {
                comps.push_back(ra[i]);
            }
        }
        sort(comps.rbegin(), comps.rend());
        int ans = 0;
        for (int i = 0; i <= fr && i < (int) comps.size(); i++) {
            ans += comps[i];
        }
        cout << ans - 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}