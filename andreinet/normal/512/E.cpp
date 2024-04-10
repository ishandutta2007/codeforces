#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 1005;

int N;
set<int> G[Nmax];
bool has1[Nmax];

void solveSegment(int left, int right, bool mode, vector<pair<int, int>>& ans) {
    if (left + 1 >= right) return;
    int p = *G[right].upper_bound(left);
    if (!mode) ans.push_back({left, right});
    else ans.push_back({1, p});
    G[left].erase(right);
    G[right].erase(left);
    G[1].insert(p);
    G[p].insert(1);
    has1[p] = true;
    solveSegment(left, p, mode, ans);
    solveSegment(p, right, mode, ans);
}

vector<pair<int, int>> solve(bool mode) {
    for (int i = 1; i <= N; ++i) G[i].clear();
    memset(has1, 0, sizeof has1);

    for (int i = 1; i <= N; ++i) {
        G[i].insert(i % N + 1);
        G[i].insert((i - 2 + N) % N + 1);
    }
    has1[2] = has1[N] = true;
    for (int i = 1; i <= N - 3; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].insert(y);
        G[y].insert(x);
        if (x == 1) has1[y] = true;
        if (y == 1) has1[x] = true;
    }
    vector<pair<int, int>> ans;
    for (int i = 2; i < N; ++i) {
        if (has1[i]) {
            for (int j = i + 1; j <= N; ++j) {
                if (has1[j]) {
                    solveSegment(i, j, mode, ans);
                    break;
                }
            }
        }
    }
    if (mode) reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    cin >> N;
    vector<pair<int, int>> ans1 = solve(false);
    vector<pair<int, int>> ans2 = solve(true);
    cout << ans1.size() + ans2.size() << '\n';
    for (auto& p: ans1) cout << p.first << ' ' << p.second << '\n';
    for (auto& p: ans2) cout << p.first << ' ' << p.second << '\n';
}