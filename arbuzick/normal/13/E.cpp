#include <bits/stdc++.h>
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
vector<int> p;
vector<pair<int, int>> ans;
const int s = 540;
void change(int pos, int a) {
    p[pos] = a;
    int b = pos/s;
    for (int i = min(int(p.size()-1), (b+1)*s-1); i/s == pos/s && i >= 0; --i) {
        if ((i+p[i])/s  > pos/s || i+p[i] >= p.size()) {
            ans[i] = {1, i};
        } else {
            ans[i] = {ans[i+p[i]].f+1, ans[i+p[i]].s};
        }
    }
}
pair<int, int> get(int pos) {
    int k = 0, pr = pos;
    while (pos < p.size()) {
        k += ans[pos].f;
        pr = ans[pos].s;
        pos = pr+p[pr];
    }
    return {k, pr};
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ans.resize(n);
    p.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int a = 0; a*s < n; ++a) {
        for (int i = min(int(n-1), (a+1)*s-1); i/s == a && i >= 0; --i) {
            if ((i+p[i])/s > a || i+p[i] >= n) {
                ans[i] = {1, i};
            } else {
                ans[i] = {ans[i+p[i]].f+1, ans[i+p[i]].s};
            }
        }
    }
    while (m--) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            change(a-1, b);
        } else {
            int a;
            cin >> a;
            auto p = get(a-1);
            cout << p.s+1 << ' ' << p.f << '\n';
        }
    }
    return 0;
}