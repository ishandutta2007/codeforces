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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 303;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int n;
int dp[N * 2][N][N];
int a[N][N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void upd(int &A, int b) {
    A = max(A, b);
}

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

pair<int,int> getPos(int i, int j) {
    if (i >= n)
        j += i - n + 1;
    return mp(i - j, j); 
}

int getId(int i, int y) {
    if (i >= n)
        y -= i - n + 1;
    return y;
}

void solve() {
    memset(dp, -63, sizeof(dp));
    dp[0][0][0] = a[0][0];  

    for (int i = 0; i < n * 2 - 2; i++) {
        int len = (i < n)? i + 1: 2 * n - 1 - i;
        //db2(i, len);
        for (int j = 0; j < len; j++)
            for (int k = 0; k < len; k++) {
                auto p1 = getPos(i, j);
                auto p2 = getPos(i, k);
                for (int t1 = 0; t1 < 2; t1++) {
                    int x1 = p1.F + dx[t1];
                    int y1 = p1.S + dy[t1];
                    for (int t2 = 0; t2 < 2; t2++) {
                        int x2 = p2.F + dx[t2];
                        int y2 = p2.S + dy[t2];
                        if (check(x1, y1) && check(x2, y2)) {
                            int j1 = getId(i + 1, y1);
                            int k1 = getId(i + 1, y2);
                            int val = a[x1][y1];
                            if (x1 != x2 || y1 != y2)
                                val += a[x2][y2];
                            upd(dp[i + 1][j1][k1], dp[i][j][k] + val);
                        }
                    }
                }
                

            }
    }


    cout << dp[n * 2 - 2][0][0] << endl;
}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}