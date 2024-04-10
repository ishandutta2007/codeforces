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
const int N = 5555;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int lcp[N][N];
int dp[N][N];
char s[N];
int n;

void upd(int & a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void read() {
    scanf("%d", &n);
    scanf("%s", s);
}

void solve() {
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else
                lcp[i][j] = 0;
        }
    //for (int i = 0; i <= n; i++, cerr << endl)
        //for (int j = 0; j <= n; j++)
            //cerr << lcp[i][j] << " ";


    for (int i = 0; i < n; i++)
        dp[0][i + 1] = 1;  
    for (int i = 1; i < n; i++) {
        int sum = 0;
        if (s[i] == '0') continue;
        for (int len = 1; ; len++) {
            int l = i - len;
            int r = i + len;
            if (r > n) break;
            if (l < 0) {
                //db2(i, r);
                upd(dp[i][r], sum);
            }
            else {
                int d = lcp[l][i];
                bool flag;
                if (d >= len)
                    flag = 0;
                else {
                    if (s[l + d] < s[i + d])
                        flag = 1;
                    else
                        flag = 0;
                }
                if (flag)
                    upd(sum, dp[l][i]);
                upd(dp[i][r], sum);
                if (!flag)
                    upd(sum, dp[l][i]);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
        upd(answer, dp[i][n]); 

    printf("%d\n", answer);

    //for (int i = 0; i <= n; i++, cerr << endl)
        //for (int j = 0; j <= n; j++)
            //cerr << dp[i][j] << " ";

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