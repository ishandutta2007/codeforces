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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

vector<int> e[N];
vector<int> team[N];


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u; 
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v); v--;
            team[i].pb(v);
            mx = max(mx, v);
        }
    }
    mx++;
    vector<int> color(mx);
    for (int i = 0; i < mx; i++)
        color[i] = rand() % 2;


    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < n; i++) {
            bool has[2] = {0};
            for (auto v: team[i]) {
                has[color[v]] = 1;
            }
            if (has[0] == 0 || has[1] == 0) {
                changed = 1;
                color[team[i][rand() % team[i].size()]] ^= 1;
            }
        }
    }

    vector<int> answer(n, -1);

    for (int i = 0; i < n; i++) {
        int cnt[2] = {0};
        for (auto v: e[i]) {
            if (answer[v] != -1) { 
                cnt[color[answer[v]]]++;
            } 
        } 
        int need = cnt[0] > cnt[1]? 1: 0;
        int where = -1;
        for (auto v: team[i]) {
            if (color[v] == need) {
                where = v;
            }
        }
        assert(where != -1);
        answer[i] = where;
    }

    for (auto x: answer)
        printf("%d ", x + 1);
    puts("");
    for (int i = 0; i < mx; i++)
        printf("%d ", color[i] + 1);
    puts("");
    int good = 0;
    int bad = 0;
    for (int i = 0; i < n; i++) {
        for (auto v: e[i])
           if (v < i) {
               if (color[answer[v]] == color[answer[i]]) {
                   bad++;
               }
               else
                   good++;
           } 

    }
    db2(good, bad);

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}