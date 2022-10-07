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

struct Edge {
    int v, u, c;
};


int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Edge> e;
    for (int i = 0; i < m; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--; 
        e.pb({v, u, c});
    }
    auto ee = e;
    int q;
    scanf("%d", &q);
    map<int,vector<pair<int,vector<int>> > > mp;
    for (int i = 0; i < q; i++) {
        int len;
        scanf("%d", &len);
        vector<pair<int,int>> tmp(len);
        for (int j = 0; j < len; j++) {
            scanf("%d", &tmp[j].S); tmp[j].S--;
            tmp[j].F = e[tmp[j].S].c;
        }
        sort(all(tmp));
        for (int j = 0; j < sz(tmp);) {
            int k = j;
            for (; j < sz(tmp) && tmp[j].F == tmp[k].F; j++);
            vector<int> superId;
            for (int t = k; t < j; t++) {
                superId.pb(tmp[t].S);
            }
            mp[tmp[k].F].pb({i, superId});
        }
    }

    vector<int> answer(q, 1);

    sort(all(e), [](Edge A, Edge B) {
            return A.c < B.c;
            });

    vector<int> p(n);
    vector<int> tryP(n);
    vector<int> ver(n, -1);
    int tmr = 0;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    function<int(int)> getId = [&](int v) {
        return (p[v] == v)? v: p[v] = getId(p[v]);
    };

    function<int(int)> getIdA = [&](int v) {
        if (ver[v] != tmr) {
            tryP[v] = p[v];
            ver[v] = tmr;
        }
        if (tryP[v] == v) return v;
        return tryP[v] = getIdA(tryP[v]);
        //return (p[v] == v)? v: p[v] = getId(p[v]);
    };


    for (int i = 0; i < m; ) {
        int j = i;
        for (; i < m && e[i].c == e[j].c; i++);
        int curCost = e[j].c; 
        
        for (auto x: mp[curCost]) {
            //db("IN");
            int id = x.F;
            auto edges = x.S;
            bool ok = 1;
            tmr++;
            //db(edges.size());
            for (auto eid: edges) {
                int v = ee[eid].v;
                int u = ee[eid].u;   
                //db2(v, u);
                //dbv(tryP);
                //if (v == u) {
                    //ok = 0;
                    //break;
                //}

                v = getIdA(v);
                u = getIdA(u);

                if (v == u) {
                    ok = 0;
                    break;
                }


                //db2(v, u);
                //db(tmr);
                //dbv(ver);
                assert(ver[v] == tmr);
                assert(ver[u] == tmr);
                tryP[v] = u;
            }
            if (!ok) {
                //db(id);
                answer[id] = 0;
            }
        }

        for (; j < i; j++) {
            int v = getId(e[j].v);
            int u = getId(e[j].u);
            p[v] = u;
        }
    } 







    for (int i = 0; i < q; i++) {
        if (answer[i]) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
   
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}