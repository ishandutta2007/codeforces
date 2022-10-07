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
const int N = 111;
const int INF = 1e9;

char s[N][N];
int val[N][N];
int n, m;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            val[i][j] = (s[i][j] == 'W')? 1: -1;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) 
        for (int j = m - 1; j >= 0; j--) {
            int d = - val[i][j];
            if (d != 0) {
                for (int x = 0; x <= i; x++)
                    for (int y = 0; y <= j; y++)
                        val[x][y] += d;
                ans++;
            }
        }

    printf("%d\n", ans);
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