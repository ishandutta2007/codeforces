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


vector<int> t;


int fix(int v, int tl, int tr, int l, int r, int g) {
    if (r <= tl || tr <= l) return -1;
    if (tl + 1 == tr) {
        if (t[v] % g == 0) return -1;
        return tl;
    }
    if (l <= tl && tr <= r) {
        if (t[v] % g == 0) return -1;
        if (t[v * 2 + 1] % g != 0) {
            return fix(v * 2 + 1, tl, (tl + tr) / 2, l, r, g);
        }
        else {
            assert(t[v * 2 + 2] % g != 0);
            return fix(v * 2 + 2, (tl + tr) / 2, tr, l, r, g);
        }
    }
    if (l < (tl + tr) / 2) {
        int res = fix(v * 2 + 1, tl, (tl + tr) / 2, l, r, g);
        if (res != -1) {
            return res;
        }
        return fix(v * 2 + 2, (tl + tr) / 2, tr, l, r, g);
    }
    return fix(v * 2 + 2, (tl + tr) / 2, tr, l, r, g);
}

void assign(int v, int tl, int tr, int pos, int val) {
    if (tl + 1 == tr) {
        t[v] = val;
        return;
    }
    if (pos < (tl + tr) / 2) {
        assign(v * 2 + 1, tl, (tl + tr) / 2, pos, val);
    }
    else {
        assign(v * 2 + 2, (tl + tr) / 2, tr, pos, val);
    }
    t[v] = __gcd(t[v * 2 + 1], t[v * 2 + 2]);
}


int main(){
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    t.resize(n * 4);
    for (int i = 0; i < n; i++) {
        assign(0, 0, n, i, a[i]);
    }


    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 2) {
            x--;
            assign(0, 0, n, x, y);
            a[x]= y;
        }
        else {
            bool ok = 0;
            int g;
            scanf("%d", &g);
            int pos = fix(0, 0, n, x - 1, y, g);
            if (pos == -1) {
                ok = 1;
            }
            else {

                assign(0, 0, n, pos, g);
                int npos = fix(0, 0, n, x - 1, y, g);
                if (npos == -1) {
                    ok = 1;
                }
                assign(0, 0, n, pos, a[pos]);
            }
            if (ok) {
                puts("YES");
            }
            else {
                puts("NO");
            }
        }
    }




    return 0;
}