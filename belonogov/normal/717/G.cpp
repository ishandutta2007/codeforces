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

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e3 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


struct MinCost {
    struct Edge {
        int u, f, mf, c;
    };
    vector<int> e[N];
    vector<Edge> data;
    int st, fn, all;

    void addE(int v, int u, int f, int c) {
        e[v].pb(data.size());
        data.pb({u, 0, f, c});
        e[u].pb(data.size());
        data.pb({v, 0, 0, -c});
    }

    int flow(int need) {
        int res = 0;
        int cnt = 0;
        int _need = need;
        while (_need--) {
            vector<int> dist(all, -INF);
            vector<int> par(all, -1); 
            vector<int> parId(all, -1); 
            vector<int> inq(all, 0);
            queue<int> q;
            dist[st] = 0;
            q.push(st);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                inq[v] = 0;
                for (auto id: e[v]) {
                    auto x = data[id];
                    if (dist[x.u] < dist[v] + x.c && x.f < x.mf) {
                        dist[x.u] = dist[v] + x.c;
                        par[x.u] = v;
                        parId[x.u] = id;
                        if (!inq[x.u])
                            q.push(x.u);
                    }
                }
            }
            if (dist[fn] != -INF) {
                res += dist[fn];
                int v = fn;
                cnt++;
                for (; v != st; v = par[v]) {
                    int id = parId[v];
                    data[id].f++;
                    data[id ^ 1].f--;
                }
            }
            else
                break;

        } 
        db2(cnt, need);
        assert(cnt == need);
        return res;
    }

    
};



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int m;
    cin >> m;
    MinCost flow;
    flow.st = 0;
    flow.fn = n;
    flow.all = n + 1;


    for (int i = 0; i < m; i++) {
        string t;
        int cost;
        cin >> t >> cost;
        for (int j = 0; j <= n - (int)t.size(); j++) {
            if (s.substr(j, t.size()) == t) {
                flow.addE(j, j + t.size(), 1, cost);
            }
        }
    }
    int x;
    cin >> x;

    for (int i = 0; i < n; i++) {
        flow.addE(i, i + 1, x, 0); 
    }

    cout << flow.flow(x) << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}