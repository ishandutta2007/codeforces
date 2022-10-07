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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6;
const long long INF = 1e9 + 19;

int a[N];
int b[N];
int c[N];
int n, m;
map < int, int > q; 

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        q[a[i]]++;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &c[i]);
}

void solve() {
    int best = -1;
    pair < int, int > res(-1, -1);
    for (int i = 0; i < m; i++) {
        auto tmp = mp(q[b[i]], q[c[i]]);
        if (res < tmp) {
            res = tmp;
            best = i;
        }
    }
    printf("%d\n", best + 1);
}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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