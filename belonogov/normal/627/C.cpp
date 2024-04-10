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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
const int T = 22;

int d, n, m;
pair < int, int > b[N];
pair < int, int > table[T][N];
int deg[N];

void read() {
    scanf("%d%d%d", &d, &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &b[i].fr, &b[i].sc);
    }
}

pair < int, int > getMin(int l, int r) {
    int len = r - l;
    int j = deg[len];
    return min(table[j][l], table[j][r - (1 << j)]);
}

void solve() {
    b[m++] = mp(0, 0);
    b[m++] = mp(d, 0);
    sort(b, b + m);
    
    deg[1] = 0;
    for (int i = 2; i <= m; i++)
        deg[i] = deg[i / 2] + 1;
    for (int i = 0; i < m; i++)
        table[0][i] = mp(b[i].sc, i);
    for (int j = 1; j < T; j++)
        for (int i = 0; i + (1 << j) <= m; i++)
            table[j][i] = min(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);

    long long answer = 0; 
    int pos = 0;
    for (; pos < d;) {
        int r = upper_bound(b, b + m, mp(pos, int(INF))) - b - 1;   
        int l = upper_bound(b, b + m, mp(pos - n, int(INF))) - b;
        if (r < l) {
            puts("-1");
            return;
        }
        auto x = getMin(l, r + 1);
        int id = x.sc;
        long long t1 = n - (pos - b[id].fr);
        long long t2 = b[r + 1].fr - pos;
        long long t = min(t1, t2);
        assert(t > 0);
        pos += t;
        answer += t * 1ll * b[id].sc;
    }

    printf("%lld\n", answer);

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