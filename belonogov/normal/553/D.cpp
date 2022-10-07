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

#define equal equalll
#define less lesss
const int N = 1e5 + 10; 
const int INF = 1e9 + 19;
const int T = 35;

bool equal(double a, double b) {
    return abs(a - b) < 1e-9;
}

struct CMP {
    bool operator () (const pair < double, int > & a, const pair < double, int > & b) {
        return a.fr > b.fr || (a.fr == b.fr && a.sc < b.sc);
    }
};

int n, m, k;
char castle[N];
char take[N];
vector < int > e[N];
priority_queue < pair < double, int >, vector < pair < double, int > >, CMP > q;
int cnt[N];
vector < int > answer;


void read() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        x--;
        castle[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}



bool check(double cof) {
    memset(take, 0, sizeof(take));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
        if (!castle[i]) {
            for (auto x: e[i])
                cnt[i] += !castle[x];
            take[i] = 1;    
            q.push(mp(cnt[i] * 1.0 / e[i].size(), i));
        }
    
    while (!q.empty()) {

        int v = q.top().sc;
        double val = q.top().fr;
        q.pop();
        if (!equal(cnt[v] * 1.0 / e[v].size(), val))
            continue;
        //db(val);
        if (val >= cof)  {
            answer.clear();
            answer.pb(v);
            for (;!q.empty(); ) {
                int v = q.top().sc;
                double val = q.top().fr;
                q.pop();
                if (equal(cnt[v] * 1.0 / e[v].size(), val))
                    answer.pb(v); 
            }

            return 1;
        }

        take[v] = 0;
        for (auto u: e[v])
            if (take[u]) {
                cnt[u]--;
                q.push(mp(cnt[u] * 1.0 / e[u].size(), u));
            }
    }
    return 0;    
}

void solve() {
    //cerr << check(0.9) << endl;
    //db(answer.size());
    //exit(0);
    double l = 0;
    double r = 1.1;
    for (int tt = 0; tt < T; tt++) {
        if (check((l + r) / 2))
            l = (l + r) / 2;  
        else
            r = (l + r) / 2;
    }
    //db(l);
    if (equal(l, 0))
        l = 0;
    assert(check(l));
    //db(l);
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d ", x + 1);
    printf("\n");
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
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}