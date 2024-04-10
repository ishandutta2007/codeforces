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
const int N = 1e6;
const int INF = 1e9;


int n;
int a[N];
int p[N];
int len[N];
int used[N];

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    v = getId(v);
    u = getId(u);
    if (v == u) return;
    p[v] = u;
    len[u] += len[v];
}


void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    vector < pair < int, int > > b;
    for (int i = 0; i < n; i++)
        b.pb(mp(a[i], i));

    sort(b.begin(), b.end(), greater < pair < int, int > >());
    for (int i = 0; i < n; i++) {
        p[i] = i; 
        len[i] = 1;
        used[i] = 0;
    }

    vector < int > answer(n + 1); 
    for (auto x: b) {
        int pos = x.sc;
        used[pos] = 1;
        if (pos > 0 && used[pos - 1]) {
            int v = getId(pos - 1);
            int u = getId(pos);
            merge(v, u);
        }
        if (pos < n - 1 && used[pos + 1]) {
            int v = getId(pos + 1);
            int u = getId(pos);
            merge(v, u);
        }
        int v = getId(pos);
        answer[len[v]] = max(answer[len[v]], x.fr);
    }
    
    for (int i = n; i > 1; i--) {
        answer[i - 1] = max(answer[i - 1], answer[i]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);

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