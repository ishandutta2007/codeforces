#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005;

i64 D[2 * Nmax], H[2 * Nmax];
i64 All[8 * Nmax], Begin[8 * Nmax], End[8 * Nmax], Cont[8 * Nmax];

void build(int node, int left, int right) {
    if (left == right) {
        All[node] = 0;
        End[node] = H[left];
        Begin[node] = H[left] + D[left];
        Cont[node] = D[left];
    } else {
        int mid = (left + right) / 2;
        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);
        All[node] = max(All[2 * node], All[2 * node + 1]);
        All[node] = max(All[node], Begin[2 * node] + End[2 * node + 1]);
        Cont[node] = Cont[2 * node] + Cont[2 * node + 1];
        Begin[node] = max(Begin[2 * node + 1], Begin[2 * node] + Cont[2 * node + 1]);
        End[node] = max(End[2 * node], Cont[2 * node] + End[2 * node + 1]);
    }
}

i64 Ans, Con;
void query(int node, int left, int right, int lq, int rq) {
    if (lq > rq) return;
    if (lq <= left && right <= rq) {
        Ans = max(Ans, All[node]);
        Ans = max(Ans, Con + End[node]);
        Con = max(Begin[node], Con + Cont[node]);
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) query(2 * node, left, mid, lq, rq);
        if (rq > mid) query(2 * node + 1, mid + 1, right, lq, rq);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d", &x);
        D[i] = x;
    }
    for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d", &x);
        H[i] = x;
        H[i] *= 2;
    }
    for (int i = N + 1; i <= 2 * N; ++i) {
        D[i] = D[i - N];
        H[i] = H[i - N];
    }
    build(1, 1, 2 * N);
    while (M--) {
        int l, r;
        scanf("%d%d", &l, &r);

        if (l <= r) {
            Ans = 0, Con = 0;
            query(1, 1, 2 * N, r + 1, N + l - 1);

            cout << Ans << '\n';
        } else {
            Ans = 0, Con = 0;
            query(1, 1, 2 * N, r + 1, l - 1);

            cout << Ans << '\n';
        }
    }
}