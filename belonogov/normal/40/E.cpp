#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;


int main(){
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int k;
    scanf("%d", &k);
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<int> curScoreX(n, 1);
    vector<int> curScoreY(m, 1);
    vector<int> cntX(n);
    vector<int> cntY(m);
    for (int i = 0; i < k; i++) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c); x--; y--;
        a[x][y] = c;
        cntX[x]++;
        cntY[y]++;
        if (c == -1) {
            curScoreX[x] *= -1;
            curScoreY[y] *= -1;
        }
    }

    int p;
    scanf("%d", &p);


    vector<int> usex(n);
    vector<int> usey(m);

    vector<int> xx;
    vector<int> yy;
    function<void(int, int)> dfs = [&](int x, int type) {
        if (type == 0) {
            xx.pb(x);
            usex[x] = 1;
            for (int i = 0; i < m; i++) {
                if (a[x][i] == 0 && usey[i] == 0) {
                    dfs(i, 1);
                }
            }
        }
        else {
            int y = x;
            yy.pb(y);
            usey[y] = 1;
            for (int i = 0; i < n; i++) {
                if (a[i][y] == 0 && usex[i] == 0) {
                    dfs(i, 0);
                }
            }
        }
    };
    bool fail = 0;
    for (int i = 0; i < n; i++) {
        if (cntX[i] == m && curScoreX[i] == 1) fail = 1;
    }
    for (int i = 0; i < m; i++) {
        if (cntY[i] == n && curScoreY[i] == 1) fail = 1;
    }


    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (usex[i] == 0 && cntX[i] != m) {
            xx.clear();
            yy.clear();
            dfs(i, 0);
            assert(!xx.empty() && !yy.empty());
            int mul = 1;
            for (auto x: xx) { mul *= curScoreX[x]; }
            for (auto y: yy) { mul *= curScoreY[y]; }

            if ((xx.size() + yy.size()) % 2 == 1) {
                mul *= -1;
            }
            if (mul == -1) {
                fail = 1;
            }
            int cntIn = 0;
            for (auto x: xx) {
                for (auto y: yy) {
                    if (a[x][y] == 0) {
                        cntIn++;
                    }
                }
            }
            //db3(cntIn, xx.size(), yy.size());
            cnt += max(0, cntIn - (int)xx.size() - (int)yy.size() + 1);
        }
    }

    if (fail) {
        puts("0");
    }
    else {
        ll x = 1;
        for (int i = 0; i < cnt; i++) {
            x = (x * 2) % p;
        }
        cout << x << endl;
    }

    return 0;
}