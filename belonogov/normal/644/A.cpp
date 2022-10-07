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
const int N = 1100;
const long long INF = 1e9 + 19;


int n, a, b;
int c[N][N];

void read() {
    scanf("%d%d%d", &n, &a, &b);
    if (a * b < n) {
        puts("-1");
        return;
    }
    vector < int > tmp[2];
    for (int i = 1; i <= n; i++)
        tmp[(i - 1) % 2].pb(i);
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++) {
            int d = (i + j) % 2;
            if (!tmp[(i + j) % 2].empty()) {
                c[i][j] = tmp[d].back();
                tmp[d].pop_back();
            }
        }
    for (int i = 0; i < a; i++, puts(""))
        for (int j = 0; j < b; j++)
            printf("%d ", c[i][j]);
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