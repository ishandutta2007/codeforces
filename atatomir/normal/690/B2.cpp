#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 555

struct cell {
    int set_zero, set_one, non_set;
    int black;

    void reset() {
        set_zero = set_one = 0; non_set = 4;
        black = 0;
    }

    void add_zero() {
        set_zero++;
        non_set--;
    }

    void add_one() {
        set_one++;
        non_set--;
    }

    bool can_deduce() {
        return (black == set_one + non_set) || (4 - black == set_zero + non_set);
    }
};

int n, i, j;
char s[maxN];
cell C[maxN][maxN];
int tp[maxN][maxN];
bool in_queue[maxN][maxN];
queue< pair<int, int> > Q;

int limit;
vector< pair<int, int> > P, Hull;


void set_tp(int x, int y, int v) {
    if (x == 0 || y == 0) return;

    tp[x][y] = v;
    if (v == 0) {
        C[x - 1][y - 1].add_zero();
        C[x][y - 1].add_zero();
        C[x - 1][y].add_zero();
        C[x][y].add_zero();
    } else {
        C[x - 1][y - 1].add_one();
        C[x][y - 1].add_one();
        C[x - 1][y].add_one();
        C[x][y].add_one();
    }

    for (int px = -1; px <= 0; px++)
        for (int py = -1; py <= 0; py++)
            if (!in_queue[x + px][y + py])
                if (C[x + px][y + py].can_deduce())
                    Q.push(mp(x + px, y + py));

}

void add_zero(int x, int y) {
    set_tp(x, y, 0);
}

void add_one(int x, int y) {
    set_tp(x, y, 1);
    P.pb(mp(x, y));
}

int cross(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    B.first -= A.first;
    B.second -= A.second;

    C.first -= A.first;
    C.second -= A.second;

    return B.first * C.second - B.second * C.first;
}

void solve() {
    int i, j;
    int dim = n + 1;

    P.clear();
    for (i = 1; i <= dim; i++) {
        for (j = 1; j <= dim; j++) {
            if (!C[i][j].can_deduce()) continue;
            Q.push(mp(i, j));
            in_queue[i][j] = true;
        }
    }

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        if (C[x][y].black == C[x][y].set_one + C[x][y].non_set) {
            //! set all one
            if (tp[x][y] == -1) tp[x][y] = 1, add_one(x, y);
            if (tp[x + 1][y] == -1) tp[x + 1][y] = 1, add_one(x + 1, y);
            if (tp[x][y + 1] == -1) tp[x][y + 1] = 1, add_one(x, y + 1);
            if (tp[x + 1][y + 1] == -1) tp[x + 1][y + 1] = 1, add_one(x + 1, y + 1);
        } else {
            //! set all zero
            if (tp[x][y] == -1) tp[x][y] = 0, add_zero(x, y);
            if (tp[x + 1][y] == -1) tp[x + 1][y] = 0, add_zero(x + 1, y);
            if (tp[x][y + 1] == -1) tp[x][y + 1] = 0, add_zero(x, y + 1);
            if (tp[x + 1][y + 1] == -1) tp[x + 1][y + 1] = 0, add_zero(x + 1, y + 1);
        }
    }

    //! build convex Hull
    Hull.clear();
    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());
    dim = 2;
    for (auto p : P) {
        while (Hull.size() >= dim) {
            if (cross(Hull[Hull.size() - 2], Hull.back(), p) < 0) break;
            Hull.pop_back();
        }
        Hull.pb(p);
    }

    P.pop_back();
    reverse(P.begin(), P.end());
    dim = Hull.size() + 1;
    for (auto p : P) {
        while (Hull.size() >= dim) {
            if (cross(Hull[Hull.size() - 2], Hull.back(), p) < 0) break;
            Hull.pop_back();
        }
        Hull.pb(p);
    }

    Hull.pop_back();

    printf("%d\n", Hull.size());
    for (auto e : Hull) printf("%d %d\n", e.first - 1, e.second - 1);
}

int main()
{
    //freopen("test.in","r",stdin);

    while(scanf("%d\n", &n)) {
        if (n == 0) return 0;

        for (i = 0; i <= n + 3; i++)
            for (j = 0; j <= n + 3; j++)
                C[i][j].reset(), tp[i][j] = -1, in_queue[i][j] = false;

        for (i = 1; i <= n; i++) {
            scanf("%s\n", s + 1);
            for (j = 1; j <= n; j++)
                C[j][n - i + 1].black = s[j] - '0';
        }

        solve();
    }


    return 0;
}