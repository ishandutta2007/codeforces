#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 150005;

double S[Nmax], P[Nmax];
double Aint1[4 * Nmax], Aint2[4 * Nmax], Aint3[4 * Nmax];

void build(int node, int left, int right) {
    if (left == right) {
        Aint1[node] = Aint2[node] = S[left] - P[left];
        Aint3[node] = 0;
    } else {
        int mid = (left + right) / 2;
        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);
        Aint1[node] = min(Aint1[2 * node], Aint1[2 * node + 1]);
        Aint2[node] = max(Aint2[2 * node], Aint2[2 * node + 1]);
        Aint3[node] = max(max(Aint3[2 * node], Aint3[2 * node + 1]), Aint2[2 * node + 1] - Aint1[2 * node]);
    }
}

double mins, maxs, tmax;

void query(int node, int left, int right, int lq, int rq) {
    if (lq <= left && right <= rq) {
        tmax = max(tmax, Aint3[node]);
        tmax = max(tmax, Aint2[node] - mins);
        mins = min(mins, Aint1[node]);
        maxs = max(maxs, Aint2[node]);
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) query(2 * node, left, mid, lq, rq);
        if (rq > mid) query(2 * node + 1, mid + 1, right, lq, rq);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cout << setprecision(9) << fixed;

    int N, M, C;
    cin >> N >> M >> C;

    --N;
    int start;
    cin >> start;

    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        S[i] = (double) (x - start) / 2;
    }
    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        P[i] = P[i - 1] + (double) x / 100 * C;
    }

    build(1, 0, N);

    double ans = 0;
    while (M-- > 0) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        mins = 1e99;
        maxs = -1e99;
        tmax = 0;
        query(1, 0, N, x, y);
        ans += tmax;
    }
    cout << ans << '\n';
}