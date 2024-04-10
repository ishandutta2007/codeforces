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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

struct Edge {
    int v, u, c;
};

int n, m;
Edge g[N];
int res = INF;
vector < int > answer;
vector < pair < int, int > > e[N];
int color[N];
vector < int > cnt[2];
bool flag;


void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        char ch;
        scanf("%d%d %c", &g[i].v, &g[i].u, &ch);
        g[i].v--;
        g[i].u--;
        assert(ch == 'B' || ch == 'R');
        g[i].c = ch == 'B';
    }
}

void dfs(int v, int c) {
    color[v] = c;
    cnt[c].pb(v);
    //db2(v, c);
    for (auto x: e[v]) {
        int need = c ^ x.sc;
        if (color[x.fr] == -1) {
            dfs(x.fr, need);
        }
        else {
            if (color[x.fr] != need) {
                flag = 0;
                //db("fail");
            }
        }
    }
}


void solve() {
    for (int t = 0; t < 2; t++) {
        //cerr << endl;
        //db(t);
        for (int i = 0; i < n; i++)
            e[i].clear();
        
        for (int i = 0; i < m; i++) {
            e[g[i].v].pb(mp(g[i].u, g[i].c));
            e[g[i].u].pb(mp(g[i].v, g[i].c));
        }     
        //for (int i = 0; i < n; i++) {
            //for (auto x: e[i])
                //cerr << "(" << x.fr << ", " << x.sc << ")   ";
            //cerr << endl;
        //}

        for (int i = 0; i < n; i++)
            color[i] = -1;

        flag = 1;
        vector < int > tmp;
        for (int i = 0; i < n; i++)
            if (color[i] == -1) {
                cnt[0].clear();
                cnt[1].clear();
                dfs(i, 0);
                if (cnt[0].size() > cnt[1].size())
                    swap(cnt[0], cnt[1]);
                for (auto x: cnt[0])
                    tmp.pb(x); 
            }
        //db(flag):
        if (flag) {
            if (res > (int)tmp.size()) {
                res = tmp.size();
                answer = tmp;
            }
        }
         
        for (int i = 0; i < m; i++)
            g[i].c ^= 1;
    }

    if (res < INF) {
        assert(res == (int)answer.size());
        printf("%d\n", (int)answer.size());
        for (auto v: answer)
            printf("%d ", v + 1);
        puts("");
    }
    else {
        puts("-1");
    }

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}