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
/*
set<pair<int,int>> q;

void rec(ll x, ll y) {
    if (x > y) {
        swap(x, y);
    }
    if (q.insert({x, y}).S) {
        if (q.size() % 1000 == 0) {
            db(q.size());
        }
        ll mx = max(x, y);
        for (int k = 2; k * k * mx <= INF; k++) {
            if (y * k * k <= INF && x * k <= INF)
                rec(x * k, y * k * k);
            if (y * k <= INF && x * k * k <= INF)
                rec(x * k * k, y * k);
        }
    }
}
*/

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    //rec(1, 1);   
    //db(q.size());
    const int T = 4e4;
    vector<int> pr;
    vector<int> lp(T);
    for (int i = 2; i < T; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0; j < sz(pr) && pr[j] * i < T && pr[j] <= lp[i]; j++) {
            lp[i * pr[j]] = lp[i];
        }
    }
    vector<vector<pair<int,int>>> comb;
    for (auto p: pr) {
        comb.pb(vector<pair<int,int>>());
        ll fp = 1;
        for (int x = 0; fp < INF; fp *= p, x++) {
            ll gp = 1;
            for (int y = 0; gp < INF; gp *= p, y++) {
                if ((x + y) % 3 == 0 && min(x, y) * 2 >= max(x, y)) {
                    comb.back().pb({fp, gp});
                }
            }
        }
    }

    vector<pair<int,int>> cand;

    function<void(int, int, int)> rec = [&](int x, int y, int pos) {
        if (pos == -1) {
            if (x <= y)
                cand.pb({x, y});
            //db3(x, y, pos);
            //if (cand.size() % 1000 == 0) {
                //db(cand.size());
            //}
            return;
        }
        for (auto f: comb[pos]) {       
            if (x * 1ll *  f.F < INF && y * 1ll * f.S < INF) {
                rec(x * f.F, y * f.S, pos - 1);
            }
        }

    };
    rec(1, 1, comb.size() - 1); 
    db(cand.size());
    sort(all(cand));

    //dbv(pr);
    db(pr.size());

    //auto toPrime = [&](int x) {
        
    //};

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            swap(a, b);
        } 
        int pos = lower_bound(all(cand), make_pair(a, b)) - cand.begin();
        if (cand[pos] == make_pair(a, b)) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}