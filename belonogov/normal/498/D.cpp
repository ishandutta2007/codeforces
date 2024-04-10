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
const int T = 60;



int n, m;
int a[N];
int tree[N * 4][T];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
}

void upd(int v) {
    for (int i = 0; i < T; i++)
        tree[v][i] = tree[v * 2 + 2][(tree[v * 2 + 1][i] + i) % T] + tree[v * 2 + 1][i];
}

void build(int v, int ll, int rr) {
    if (ll + 1 == rr) {
        for (int i = 0; i < T; i++)
            tree[v][i] = 1 + ((i % a[ll]) == 0);
        return;
    }
    build(v * 2 + 1, ll, (ll + rr) / 2);
    build(v * 2 + 2, (ll + rr) / 2, rr);
    upd(v);    
}

int get(int v, int ll, int rr, int l, int r, int time) {
    if (ll >= r || l >= rr) return 0;
    if (l <= ll && rr <= r) {
        return tree[v][time];
    }
    int r1 = get(v * 2 + 1, ll, (ll + rr) / 2, l, r, time);
    int r2 = get(v * 2 + 2, (ll + rr) / 2, rr, l, r, (time + r1) % T);
    return r1 + r2;
}

void apply(int v, int ll, int rr, int pos, int x) {
    if (pos < ll || pos >= rr) return;
    if (ll + 1 == rr) {
        a[pos] = x; 
        for (int i = 0; i < T; i++)
            tree[v][i] = 1 + ((i % a[ll]) == 0);
        return;
    }
    apply(v * 2 + 1, ll, (ll + rr) / 2, pos, x);
    apply(v * 2 + 2, (ll + rr) / 2, rr, pos, x);
    upd(v);
}

void solve() {
    build(0, 0, n);
    for (int i = 0; i < m; i++) {
        char ch;
        int l, r;
        scanf(" %c%d%d", &ch, &l, &r);
        assert(ch == 'A' || ch == 'C');
        if (ch == 'A') {
            l--;
            r--;
            printf("%d\n", get(0, 0, n, l, r, 0));
        }
        else {
            apply(0, 0, n, l - 1, r);
        }
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