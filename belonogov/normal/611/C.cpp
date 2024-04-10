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
const int N = 1111;
const int M = 1e6;
const long long INF = 1e9 + 19;

int n, m;
char s[N][N];
int b1[N][N];
int b2[N][N];
int pref1[N][N];
int pref2[N][N];
int q;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (s[i][j] == '.' && s[i][j + 1] == '.')
                b1[i][j]++;
        }
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.' && s[i + 1][j] == '.')
                b2[i][j]++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            pref1[i + 1][j + 1] = pref1[i + 1][j] + pref1[i][j + 1] + b1[i][j] - pref1[i][j];
            pref2[i + 1][j + 1] = pref2[i + 1][j] + pref2[i][j + 1] + b2[i][j] - pref2[i][j];
        }

    scanf("%d", &q); 
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2); x1--; y1--;
        int sum = 0;
        sum += pref1[x2][y2 - 1] - pref1[x1][y2 - 1] - pref1[x2][y1] + pref1[x1][y1];
        sum += pref2[x2 - 1][y2] - pref2[x1][y2] - pref2[x2 - 1][y1] + pref2[x1][y1];
        printf("%d\n", sum);
    }

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