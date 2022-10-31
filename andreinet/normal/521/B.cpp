#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005, Mod = 1e9 + 9;

vector<int> G[Nmax], Gt[Nmax];
int deg[Nmax], invDeg[Nmax];

bool erased[Nmax];

pair<int, int> A[Nmax];

bool goodNode(int x) {
    for (int p: Gt[x])
        if (invDeg[p] == 1)
            return false;
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    map<pair<int, int>, int> points;
    for (int i = 0; i < N; ++i) {
        pair<int, int> x;
        cin >> x.first >> x.second;

        points[x] = i;
        A[i] = x;
    }

    for (auto &p: points) {
        auto& x = p.first;
        int ind = p.second;
        for (int d = -1; d <= 1; ++d) {
            auto it = points.find(make_pair(x.first + d, x.second - 1));
            if (it == points.end()) continue;
            deg[it->second]++;
            G[ind].push_back(it->second);
            invDeg[ind]++;
            Gt[it->second].push_back(ind);
        }
    }

    set<int> Q;
    for (int i = 0; i < N; ++i)
        if (goodNode(i))
            Q.insert(i);

    int ans = 0;

    int step = 0;
    while (!Q.empty()) {
        auto it = Q.end();
        if ((step & 1) == 1) it = Q.begin();
        else --it;

        int val = *it;
        Q.erase(it);
        erased[val] = true;

        ans = (1LL * ans * N + val) % Mod;
        for (int p: Gt[val]) {
            invDeg[p]--;
            if (invDeg[p] == 1) {
                for (int l: G[p]) {
                    auto it1 = Q.find(l);
                    if (it1 != Q.end())
                        Q.erase(it1);
                }
            }
        }
        invDeg[val] = 0;
        for (int p: G[val]) {
            deg[p]--;
            if (goodNode(p) && !erased[p])
                Q.insert(p);
        }
        ++step;
    }

    cout << ans << '\n';
}