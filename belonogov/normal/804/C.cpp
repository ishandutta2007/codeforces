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
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = 3e5 + 10;
const ll INF = 1.01e9;
typedef vector<int> vi;

int n, m;
vector<int> e[N];
vector<int> who[N];
int answer[N];
int cuse[N];


void dfs(int v, int p) {
    set<int> usedColor;
    vector<int> needColor;
    for (auto ice: who[v]) {
        if (cuse[ice]) {
            usedColor.insert(answer[ice]);
        } 
        else {
            needColor.pb(ice);
            cuse[ice] = 1;
        }
    }  
    int cur = 0;
    for (auto x: needColor) {
        for (; usedColor.count(cur) == 1; cur++);
        answer[x] = cur;
        cur++;
    } 

    for (auto u: e[v])
        if (u != p)
            dfs(u, v);

}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        who[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &who[i][j]);
            who[i][j]--;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    
    dfs(0, -1);    
    int mx = 0;
    for (int i = 0; i < m; i++)
        mx = max(mx, answer[i]);
    printf("%d\n", mx + 1);
    for (int i = 0; i < m; i++)
        printf("%d ", answer[i] + 1);
    puts("");

#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}