#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 2e5 + 10;
const int INF = 1e9;

int n;
vector < pair < int, int > > e[N];
int w[N];
long long cnt[N];
long long all;
bool use[N];

long long C3(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}


void read() {
    scanf("%d", &n);
    all = C3(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--;
        e[v].pb(mp(u, i));
        e[u].pb(mp(v, i));
        w[i] = c;
    }
}

int dfs(int v) {
    use[v] = 1;
    int cntC= 1;
    for (auto x: e[v])
        if (!use[x.fr]) {
            int t = dfs(x.fr);
            cnt[x.sc] = all - (C3(t) + C3(n - t));
            cntC += t;
        }
    return cntC;
}

void solve() {
    dfs(0);
    double sum = 0;
    //for (int i = 0; i < n; i++)
        //cerr << cnt[i] << " ";
    //cerr << endl;

    for (int i = 0; i < n - 1; i++)
        sum += w[i] * cnt[i];
    int q;
    scanf("%d", &q);
    //cerr << sum << endl;
    for (int i = 0; i < q; i++) {
        int id, newW;
        scanf("%d%d", &id, &newW); id--;
        int d = w[id] - newW;
        //cerr << "d: " << endl;
        sum -= d * cnt[id];
        w[id] = newW;
        printf("%.15lf\n", sum * 2 / all);
    }
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}