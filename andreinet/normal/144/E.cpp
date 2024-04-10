#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int Nmax = 100005;

pair<int, int> A[Nmax];
int Ans[Nmax];
int Aib1[Nmax], Aib2[Nmax];

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return make_pair(a.second + a.first, a.first) < make_pair(b.second + b.first, b.first);
    }
};

void aib_update(int Aib[], int pos) {
    for (; pos < Nmax; pos += pos & -pos)
        Aib[pos]++;
}

void aib_update(int x, int y, int N) {
    aib_update(Aib1, y);
    aib_update(Aib2, N - x + 1);
}

int aib_query(int Aib[], int pos) {
    int ret = 0;
    for (; pos > 0; pos -= pos & -pos)
        ret += Aib[pos];
    return ret;
}

int aib_query(int x, int y, int N) {
    return aib_query(Aib1, y) - aib_query(Aib2, N - x);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    map<pair<int, int>, int> Pos;
    for (int i = 1; i <= M; ++i) {
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
        Pos[make_pair(x, y)] = i;
    }
    sort(A + 1, A + M + 1);

    set<int> S;
    for (int i = 1; i <= N; ++i)
        S.insert(i);

    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        int right = A[i].second, left = N - A[i].first;
        auto it = S.upper_bound(right);
        if (it == S.begin()) continue;
        --it;
        if (*it > left) {
            Ans[++ans] = Pos[A[i]];
            S.erase(it);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= ans; ++i)
        cout << Ans[i] << ' ';
    cout << endl;
}