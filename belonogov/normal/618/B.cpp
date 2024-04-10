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
const int N = 100;
const long long INF = 1e9 + 19;


int n;
int a[N][N]; 

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

int p[N];
bool use[N];

void solve() {
    for (int t = 1; t <= n; t++) {
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (use[i]) continue;
            bool flag = 1;
            for (int j = 0; j < n; j++) 
                flag &= a[i][j] <= t;
            if (flag) {
                //assert(res == -1 || i > );
                res = i;
                use[i] = 1;
                break;
            }
        }
        p[res] = t; 
    }
    for (int i = 0; i < n; i++)
        printf("%d ", p[i]);
    puts("");

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