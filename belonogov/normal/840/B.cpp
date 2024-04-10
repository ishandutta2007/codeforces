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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    vector<int> negPos;
    int cntOne = 0;
    forn(i, n) {
        scanf("%d", &a[i]);
        if (a[i] == -1) {
            negPos.pb(i);
        }
        cntOne += a[i] == 1;
    }
    if (cntOne % 2 == 1 && negPos.empty()) {
        puts("-1");
        return 0;
    }
    if (cntOne % 2 == 1) {
        a[negPos.back()] = 1;
        negPos.pop_back();
    }
    for (auto x: negPos)
        a[x] = 0;

    vector<vector<pair<int,int>>> e(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb({u, i});
        e[u].pb({v, i});
    }
    vector<int> use(n);
    vector<int> answer;
   
    function<int(int, int)> dfs = [&](int v, int id) {
        use[v] = 1;
        int sum = a[v];
        for (auto x: e[v]) {
            int u = x.F;
            if (!use[u]) {
                sum += dfs(u, x.S);
            }
        }
        if (sum % 2 == 1) {
            assert(id != -1);
            answer.pb(id);
        }
        return sum % 2;
    };
    dfs(0, -1);

    printf("%d\n", sz(answer));

    for (auto x: answer)
        printf("%d ", x + 1);
    puts("");







    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}