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
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1111;
const long long INF = 1e9 + 19;
typedef long long ll;
const int MOD = 1e9 + 7;

ll dp[N][N][2];
void add(ll& A, ll B) {
    A = (A + B) % MOD;
}

int main(){
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            add(dp[i + 1][j][1], dp[i][j][1]); // 0
            add(dp[i + 1][j + 1][1], dp[i][j][1]); // 1
            if (s[i] == '0') {
                add(dp[i + 1][j][0], dp[i][j][0]); // 0
            }
            else {
                add(dp[i + 1][j][1], dp[i][j][0]); // 0
                add(dp[i + 1][j + 1][0], dp[i][j][0]); // 1
            }
        }
    }

    // k >= 6 -> 0
    if (k == 0) {
        puts("1");
        return 0;
    }

    k--;
    set<int> cand;
    cand.insert(1);
    for (int i = 0; i < k; i++) {
        set<int> gg;
        for (auto x: cand) {
            for (int mask = 2; mask < 1024; mask++) {
                if (__builtin_popcount(mask) == x) {
                    gg.insert(mask);
                }
            }
        }
        cand = gg;
        dbv(cand);
        //for (auto x: cand) { }
    }
    ll answer = 0;

    for (auto x: cand) {
        add(answer, dp[n][x][0]);
        add(answer, dp[n][x][1]);
        //db2(answer, x);
    }
    if (k == 0) {
        answer = (answer - 1 + MOD) % MOD;
    }
    cout << answer << endl;

















    return 0;
}