#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;
const int M = 123;
const string IMPOSSIBLE = "IMPOSSIBLE\n";

struct Segment {
    int l, r;
    Segment() : l(INF), r(-INF) {}
    Segment(int l, int r) : l(l), r(r) {}

    void add(int x) {
        l = min(l, x);
        r = max(r, x + 1);
    }

    Segment operator * (const Segment &to) const {
        Segment ans;
        ans.l = min(l, to.l);
        ans.r = max(r, to.r);
        return ans;
    }
};

bool empty(const Segment &x) {
    return x.l >= x.r;
}

bool contain(const Segment &what, const Segment &in) {
    return in.l <= what.l && what.r <= in.r;
}

int n, c;
bool d[M][M];
int link[M][M];
Segment l[M], r[M];
bool pos = true;

void read() {
    cin >> n >> c;
    for (int i = 0; i < c; ++i) {
        int a, b;
        string type;
        cin >> a >> b >> type;
        if (a > b)
            pos = false;
        if (type[0] == 'L')
            l[a].add(b);
        else
            r[a].add(b);
    }
}

void rep(int l, int r) {
    if (r == l)
        return;
    if (r - l == 1) {
        cout << l << " ";
        return;
    }
    rep(l + 1, link[l][r]);
    cout << l << " ";
    rep(link[l][r], r);
}

void kill() {
    if (!pos) {
        cout << IMPOSSIBLE;
        return;
    }
    for (int i = 0; i <= n + 1; ++i)
        d[i][i] = true;

    /*for (int i = 1; i <= n; ++i) {
        cout << i << ": ";
        cout << "L " << l[i].l << " - " << l[i].r << "; ";
        cout << "R " << r[i].l << " - " << r[i].r << "\n";
    }*/
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i + k <= n + 1; ++i) {
            d[i][i + k] = false;
            for (int j = i + 1; j <= i + k; ++j)
                if (contain(l[i], Segment(i + 1, j)) && contain(r[i], Segment(j, i + k)) && d[i + 1][j] && d[j][i + k]) {
                    d[i][i + k] = true;
                    //cout << i << " " << i + k << "!\n";
                    link[i][i + k] = j;
                    break;
                }
        }
    if (!d[1][n + 1]) {
        cout << IMPOSSIBLE;
        return;
    }
    rep(1, n + 1);
}


int main() {
    cout.precision(12);
    cout << fixed;
    read();
    kill();
    return 0;
}