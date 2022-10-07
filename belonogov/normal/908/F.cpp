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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;


int getMaxGap(const vector<int>& v, int L, int R) {
    if (v.empty()) {
        return R - L;
    }
    int res = 0;
    res = max(res, v[0] - L);
    res = max(res, R - v.back());
    for (int i = 0; i + 1 < sz(v); i++) {
        res = max(res, v[i + 1] - v[i]);
    }
    return res;
}


int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    cin >> n;
    vector<int> g;
    vector<int> r;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        char ch;
        int p;
        scanf("%d %c", &p, &ch);
        if (ch == 'G') {
            g.pb(p);
        }
        else if (ch == 'B') {
            b.pb(p);
        }
        else if (ch == 'R') {
            r.pb(p);
        }
    }
    ll answer = 0;
    if (g.empty()) {
        if (!r.empty()) {
            answer += r.back() - r[0];
        }
        if (!b.empty()) {
            answer += b.back() - b[0];
        }
    }
    else {
        for (int tt = 0; tt < 2; tt++) {
            if (!r.empty()) {
                if (r[0] < g[0]) {
                    answer += g[0] - r[0];
                }
                if (g.back() < r.back()) {
                    answer += r.back() - g.back();
                }
            }
            swap(r, b);
        }
        
        for (int i = 0; i < sz(g) - 1; i++) {
            int L = g[i];
            int R = g[i + 1];
            vector<int> bb(lower_bound(all(b), L), lower_bound(all(b), R));
            vector<int> rr(lower_bound(all(r), L), lower_bound(all(r), R));
            ll r1 = (R - L) * 2;
            ll r2 = (R - L) * 3 - getMaxGap(bb, L, R) - getMaxGap(rr, L, R);
            answer += min(r1, r2);
        
        }
    }

    cout << answer << endl;


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}