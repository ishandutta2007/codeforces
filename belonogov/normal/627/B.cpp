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


int t1[N];
int t2[N];
int n;


void add(int * t, int pos, int val) {
    for (; pos < n; pos |= (pos + 1))
        t[pos + 1] += val;
}

int get(int * t, int r) {
    int sum = 0;
    for (; r > 0; r &= (r - 1))
        sum += t[r];
    return sum;
}
int a, b, k, q;
int c[N];
int d[N];

void read() {
    scanf("%d", &n);
    scanf("%d%d%d%d", &k, &a, &b, &q);
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type); 
        //db2(i, type);
        if (type == 1) {
            int pos, val;
            scanf("%d%d", &pos, &val); pos--;
            int nv = min(c[pos] + val, b);
            int diff = nv - c[pos];
            c[pos] = nv;
            add(t1, pos, diff);
            
            nv = min(d[pos] + val, a);
            diff = nv - d[pos];
            d[pos] = nv;
            add(t2, n - 1 - pos, diff);
        }
        if (type == 2) {
            int l;
            scanf("%d", &l); l--; 
            int r1 = get(t1, l);
            int r = l + k - 1;
            int r2 = get(t2, n - 1 - r);
            printf("%d\n", r1 + r2);
        }

    }

}

void solve() {

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