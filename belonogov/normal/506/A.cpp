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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int T = 30000;
const int N = T + 10;
const int INF = 1e9 + 19;

int n, d;
vector < int > dp[N];
int c[N];
int l[N];
int r[N];

void read() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        c[x]++;
    }
}

void upd(int & a, int b) {
    a = max(a, b);
}


void solve() {
    for (int i = 0; i <= T; i++) {
        l[i] = INF;
        r[i] = -INF;
    }
    l[d] = d;
    r[d] = d;
    for (int i = 0; i < T; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                int step = j + dx;
                if (step > 0 && i + step <= T) {
                    l[i + step] = min(l[i + step], step);
                    r[i + step] = max(r[i + step], step);
                }
            }
        }
    }
    for (int i = 0; i <= T; i++) {
        if (r[i] - l[i] + 1 > 0)
            dp[i].resize(r[i] - l[i] + 1);
    }

    dp[d][d - l[d]] = c[d];
    for (int i = 0; i < T; i++) {
        //db(i);
        for (int j = l[i]; j <= r[i]; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                int step = j + dx;
                int pos = i + step;
                if (step > 0 && pos <= T) {
                    //db(pos);
                    //db2(step, l[pos]);
                    //db2(step - l[pos], j - l[i]);
                    upd(dp[pos][step - l[pos]], dp[i][j - l[i]] + c[pos]);
                }
            } 
        }
    }

    int ans = 0;
    for (int i = 0; i <= T; i++)
        for (auto x: dp[i])
            ans = max(ans, x);
    cout << ans << endl;
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
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