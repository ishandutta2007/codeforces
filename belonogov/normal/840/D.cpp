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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;
const int F = 4;

struct Data {
    int val[F];
    int cnt[F];
    Data() {
        memset(val, -1, sizeof val);
        memset(cnt, 0, sizeof cnt);
    }
    void add(int x, int c) {
        forn(i, F) {
            if (val[i] == x) {
                cnt[i] += c;
                return;
            }
        }
        for (;c > 0; ) {
            int pos = -1;
            int mn = INF;
            forn(i, F) {
                if (cnt[i] == 0) {
                    pos = i;
                    break;
                }
                mn = min(mn, cnt[i]);
            }
            if (pos == -1) {
                int y = min(mn, c); 
                c -= y;
                forn(i, F)
                    cnt[i] -= y;
            }
            else {
                cnt[pos] = c;
                val[pos] = x;
                c = 0;
            }
        }
    }
    void add(Data other) {
        forn(i, F)
            add(other.val[i], other.cnt[i]);
    }
};


vector<Data> data;

void build(int v, int tl, int tr, vector<int>& a) {
    if (tl + 1 == tr) {
        data[v].add(a[tl], 1);
        return;
    }
    build(v * 2 + 1, tl, (tl + tr) / 2, a);
    build(v * 2 + 2, (tl + tr) / 2, tr, a);
    data[v] = data[v * 2 + 1];
    data[v].add(data[v * 2 + 2]);
}

Data ask(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return Data();
    if (l <= tl && tr <= r) {
        return data[v];
    }
    auto tmp = ask(v * 2 + 1, tl, (tl + tr) / 2, l, r);
       tmp.add(ask(v * 2 + 2, (tl + tr) / 2, tr, l, r));
    return tmp;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> a(n);
    vector<vector<int>> b(n);
    forn(i, n) {
        scanf("%d", &a[i]);
        a[i]--;
        b[a[i]].pb(i);
    } 

    auto get2 = [&](int x, int r) {
        return lower_bound(all(b[x]), r) - b[x].begin();
    };

    auto get = [&](int x, int l, int r) {
        return get2(x, r) - get2(x, l);   
    };
    
    data.resize(n * 4);
    build(0, 0, n, a);

    forn(t, q) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k); l--;
        auto res = ask(0, 0, n, l, r);
        int mn = INF;
        forn(i, F) {
            if (0 <= res.val[i] && res.val[i] < n && get(res.val[i], l, r) * k > r - l) {
                mn = min(mn, res.val[i]);
            }
        }
        if (mn == INF) {
            puts("-1");
        }
        else {
            printf("%d\n", mn + 1);
        }
    }



    



#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}