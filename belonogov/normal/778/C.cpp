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
const int N = 3e5 + 100;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

vector<pair<int,int>> e[N];
int n;
int cnt[N];

int dfs2(vector<int> tmp, int v) {
    //db3("dfs2", v, tmp.size());
    if (tmp.empty()) return 0; 
    vector<int> cur(tmp.size());

    int res = 1;
    for (int i = 0; i < (int)e[v].size(); i++) {
        vector<int> go;
        int ch = e[v][i].S;
        for (int j = 0; j < (int)tmp.size(); j++) {
            int u = tmp[j];
            for (; cur[j] < (int)e[u].size() && e[u][cur[j]].S < ch; cur[j]++);
            if (cur[j] < (int)e[u].size() && e[u][cur[j]].S == ch) {
                go.pb(e[u][cur[j]].F);
            }
        }
        res += dfs2(go, e[v][i].F);
    }
    return res;
}

void dfs(int v, int h) {
    //db2(v, h);
    for (int i = 0; i < (int)e[v].size(); i++) 
        dfs(e[v][i].F, h + 1);
    int res = 0;
    if (!e[v].empty())
        res = 1;
    for (int i = 0; i < (int)e[v].size(); i++) {
        vector<int> tmp; 
        for (int j = 0; j < i; j++)
            tmp.pb(e[v][j].F);
        res += dfs2(tmp, e[v][i].F);
    } 
    cnt[h] += res;
}


int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        char ch;
        scanf("%d%d %c", &v, &u, &ch); v--; u--;
        e[v].pb(mp(u, ch - 'a'));
    }
    for (int i = 0; i < n; i++)
        sort(all(e[i]), [](pair<int,int> A, pair<int,int> B) {
                return A.S < B.S;
                });
    dfs(0, 0); 
    //for (int i = 0; i <= n; i++)
        //cerr << cnt[i] << " ";
    //cerr << endl;

    int pos = 0;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] > cnt[pos]) {
            pos = i;
        }
    }
    printf("%d\n%d\n",  n - cnt[pos], pos + 1);

    return 0;
}