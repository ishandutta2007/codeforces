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
const int INF = 1.01e9;
const ll INF18 = 1e18;
typedef vector<int> vi;

struct Event {
    int t;
    int id, type;
    int cost, ii;
};


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    //auto printSet = [](set<pair<int,int>> f) { for (auto x: f) { db2(x.F, x.S); } };
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> bestF(n, INF);
    vector<set<pair<int,int>>> bestB(n);
    vector<Event> event;
    forn(i, m) {
        int d, f, t, c;
        scanf("%d%d%d%d", &d, &f, &t, &c); f--; t--;
        if (t == -1) {
            event.pb({d, f, 1, c, -1}); 
        }
        else {
            assert(f == -1);
            bestB[t].insert({c, i});
            event.pb({d - k, t, 2, c, i});
        }
    }

    sort(all(event), [](Event A, Event B) {
                return A.t < B.t;
            });

    ll sum = 0;
    int cntOk = 0;
    ll answer = INF18;
    for (int i = 0; i < (int)event.size();) {
        int j = i;
        for (; i < sz(event) && event[j].t == event[i].t; i++) {
            int v = event[i].id;
            if (!bestB[v].empty() && bestF[v] != INF) {
                cntOk--;
                sum -= bestB[v].begin()->F + bestF[v];
            }
            
            if (event[i].type == 1) {
                bestF[v] = min(event[i].cost, bestF[v]);
            }
            else {
                //db(bestB[v].size());
                //db2(event[i].cost, v);
                //printSet(bestB[v]);
                assert(bestB[v].erase({event[i].cost, event[i].ii}));
            }

            if (!bestB[v].empty() && bestF[v] != INF) {
                cntOk++;
                sum += bestB[v].begin()->F + bestF[v];
            }

        }
        if (cntOk == n) {
            answer = min(answer, sum);
        }
    }

    if (answer == INF18)  {
        puts("-1");
    }
    else {
        cout << answer << endl;
    }
        
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}