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
const int N = 444;
const long long INF = 1e9 + 19;

int n, m;
int a[N][N];
int b[N][N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        a[v][u] = 1;
        a[u][v] = 1;
    } 


    int answer = -1;
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                b[i][j] = (a[i][j]? 1: INF);

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    b[i][j] = min(b[i][j], b[i][k] + b[k][j]);

        answer = max(answer, b[0][n - 1]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] ^= 1;
    }
    

    if (answer > n)
        puts("-1");
    else
        printf("%d\n", answer);

}




void solve() {

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