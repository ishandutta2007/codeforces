#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------


vector<string> a;
int sx, sy, tx, ty;

bool valid(int x, int y) {
    return 0 <= x && x < a.size() && 0 <= y && y < a[0].size();
}

const int dirs[4][2] = {
        1, 0,
        -1, 0,
        0, 1,
        0, -1,
};

string solve(int allowed) {
    const int inf = 1e9;
    int n = a.size(), m = a[0].size();

    vector<vector<int>> dist(n, vector<int>(m, inf));
    dist[tx][ty] = 0;

    queue<pair<int, int>> q;
    q.push(mp(tx, ty));

    while (!q.empty()) {
        int x = q.front().fst;
        int y = q.front().snd;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = x + dirs[i][0];
            int cy = y + dirs[i][1];

            if (!valid(cx, cy)) {
                continue;
            }

            if (islower(a[cx][cy]) && !(allowed & (1 << (a[cx][cy] - 'a')))) {
                continue;
            }

            if (dist[cx][cy] > dist[x][y] + 1) {
                dist[cx][cy] = dist[x][y] + 1;
                q.push(mp(cx, cy));
            }
        }
    }

    if (dist[sx][sy] == inf) {
        string res(50 * 50 + 1, 'z' + 1);
        return res;
    }

    string res;
    vector<pair<int, int>> c({mp(sx, sy)});
    for (int iter = 0; iter < dist[sx][sy]; iter++) {
        char bst = 0;
        vector<pair<int, int>> nc;
        for (auto p : c) {
            for (int i = 0; i < 4; i++) {
                int cx = p.fst + dirs[i][0];
                int cy = p.snd + dirs[i][1];
                if (!valid(cx, cy) || dist[cx][cy] != dist[sx][sy] - iter - 1) {
                    continue;
                }
                if (!bst || bst > a[cx][cy]) {
                    bst = a[cx][cy];
                    nc.clear();
                    nc.pb(mp(cx, cy));
                } else if (bst == a[cx][cy]) {
                    nc.pb(mp(cx, cy));
                }
            }
        }
        res += bst;
        sort(nc.begin(), nc.end());
        nc.resize(unique(nc.begin(), nc.end()) - nc.begin());
        c = nc;
    }

    res.pop_back();
    return res;
}


int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m, k;
    scanf("%d %d %d\n", &n, &m, &k);

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                sx = i, sy = j;
            } else if (a[i][j] == 'T') {
                tx = i, ty = j;
            }
        }
    }

    int cnt = 0, allowed = 0;
    string ans(50 * 50 + 1, 'z' + 1);

    function<void(int)> rec;
    rec = [&](int p) {
        if (p == 26) {
            auto r = solve(allowed);
            if (r.size() < ans.size()) {
                ans = r;
            } else if (r.size() == ans.size()) {
                chmin(ans, r);
            }
            return;
        }

        if (cnt + 1 <= k) {
            allowed ^= 1 << p;
            cnt++;
            rec(p + 1);
            cnt--;
            allowed ^= 1 << p;
        }

        rec(p + 1);
    };

    rec(0);

    if (ans[0] == 'z' + 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}