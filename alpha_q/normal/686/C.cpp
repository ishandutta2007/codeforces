#include <bits/stdc++.h>

using namespace std;

bool mark[8];
int n, m, N, M, MAX = 823543;

int cnt (int x) {
    if (x == 0) return 1;
    int res = 0;
    while (x) {
        res++;
        x /= 7;
    }
    return res;
}

bool check (int x, int y) {
    memset(mark, 0, sizeof mark);
    int cntx = 0, cnty = 0;

    if (x == 0) {
        mark[0] = 1;
        cntx = 1;
    } else {
        while (x) {
            int dig = x % 7;
            if (mark[dig]) return 0;
            mark[dig] = 1;
            x /= 7;
            ++cntx;
        }
    }

    if (mark[0]) {
        if (N > cntx) return 0;
    } else {
        if (N - cntx > 1) return 0;
        else if (N - cntx == 1) mark[0] = 1;
    }

    if (y == 0) {
        if (mark[0]) return 0;
        mark[0] = 1;
        cnty = 1;
    } else {
        while (y) {
            int dig = y % 7;
            if (mark[dig]) return 0;
            mark[dig] = 1;
            y /= 7;
            ++cnty;
        }
    }

    if (mark[0]) {
        if (M > cnty) return 0;
    } else {
        if (M - cnty > 1) return 0;
        else if (M - cnty == 1) mark[0] = 1;
    }

    return 1;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    N = cnt(n - 1), M = cnt(m - 1);

    if (N + M > 7) {
        cout << 0 << endl;
        return 0;
    }

    int Ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (check(i, j)) {
                ++Ans;
            }
        }
    }

    cout << Ans << endl;

    cout.flush();
    return 0;
}