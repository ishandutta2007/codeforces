#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int NMAX = 100005;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> used, nused;
    for (int i = 0; i < m; ++i) {
        int w, v;
        cin >> w >> v;
        (v ? used: nused).push_back(make_pair(w, i));
    }

    sort(used.begin(), used.end());
    sort(nused.begin(), nused.end());

    vector<pair<int, int>> ans(m);
    int r = 1;
    for (pair<int, int> curr: used) {
        ans[curr.second] = make_pair(r, r + 1);
        r++;
    }

    int pnode = 3, nnode = 1;
    for (pair<int, int> curr: nused) {
        if (nnode < 1) {
            pnode++;
            nnode = pnode - 2;
        }
        int ccost = used[pnode - 2].first;
        if (curr.first < ccost) {
            cout << "-1\n";
            return 0;
        }
        ans[curr.second] = make_pair(pnode, nnode);
        nnode--;
    }

    for (pair<int, int> p: ans)
        cout << p.first << ' ' << p.second << '\n';
}