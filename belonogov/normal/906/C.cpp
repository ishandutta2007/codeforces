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
const int N = 22;
const int INF = 1.01e9;
typedef vector<int> vi;


int e[N];

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    //freopen("test.txt", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);   
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v] |= pw(u);
        e[u] |= pw(v);
    }

    bool full = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            full &= ((e[i] & pw(j)) != 0);
        }
    }
    if (full) {
        puts("0");
        return 0;
    }

    
    //queue<int> q;
    vector<int> q;
    vector<int> use(pw(n));
    for (int i = 0; i < n; i++) {
        use[pw(i)] = 1;
        q.pb(pw(i));
    }
    int curQ = 0;

    int answer = -1;
    while (curQ < sz(q)) {
        //db2(curQ, sz(q));
        //assert(sz
        int mask = q[curQ++];
        int edge = 0; 
        for (int i = 0; i < n; i++) {
            if (mask & pw(i)) {
                edge |= e[i];
            }
        }
        if ((edge | mask) == (pw(n) - 1)) {
            answer = mask; 
            break;
        }
        for (int i = 0; i < n; i++) {
            if ((edge & pw(i)) && (mask & pw(i)) == 0) {
                int nmask = mask | pw(i);
                if (!use[nmask]) {
                    q.pb(nmask);
                    use[nmask] = 1;
                }
            }
        }
    }
    assert(answer != -1);

    vector<int> who; 

    for (int i = 0; i < n; i++) {
        if (answer & pw(i)) {
            who.pb(i);
        }
    }
    vector<int> rr;
    vector<int> megaUse(n);

    function<void(int)> dfs = [&](int v) {
        megaUse[v] = 1;
        rr.pb(v);
        for (auto u: who) {
            if (e[v] & pw(u) && megaUse[u] == 0) {
                dfs(u);
            }
        }
    };

    dfs(who[0]);
    
    assert(who.size() == rr.size());

    cout << rr.size() << endl;
    for (auto x: rr) {
        cout << x + 1 << " ";
    }
    cout << endl;



    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}