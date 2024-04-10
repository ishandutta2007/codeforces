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

using namespace std;

#define F first
#define S second
#define mp make_pair
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
const int N = 555;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int LOG = 62;

int n, m;
bitset<N> e[N][LOG][2];
bitset<N> r[N][LOG][2]; 


int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, t;
        scanf("%d%d%d", &v, &u, &t); v--; u--;
        e[v][0][t][u] = 1;
        r[u][0][t][v] = 1;
    }
    for (int t = 1; t < LOG; t++) {
        for (int d = 0; d < 2; d++) {
            for (int v = 0; v < n; v++) {
                for (int u = 0; u < n; u++) {
                    bool can = (e[v][t - 1][d] & r[u][t - 1][d ^ 1]).any();
                    e[v][t][d][u] = can;
                    r[u][t][d][v] = can;
                }
            }
        }
    }



    if (e[0][LOG - 1][0].any()) {
        puts("-1");
        return 0;
    }

    ll answer = 0;
    vector<int> who;
    who.pb(0);
    int type = 0;
    //db(e[0][0][0].any());
    for (int i = LOG - 1; i >= 0; i--) {
        set<int> next; 
        for (auto v: who) {
            for (int j = 0; j < n; j++)
                if (e[v][i][type][j])
                    next.insert(j);
        }
        if (!next.empty()) {
            answer += pw(i);
            who = vector<int>(all(next));
            type ^= 1;
        }
    }

    if (answer >= (ll)1e18) {
        puts("-1");
        return 0;
    }
    cout << answer << endl;




    return 0;
}