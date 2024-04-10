#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 1000000007;
const ld eps = 1e-07;

int n, m;
string s, t;
int dp[5100][5100];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf(" ");
    getline(cin, s);
    scanf(" ");
    getline(cin, t);
    n = s.size();
    m = t.size();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = (dp[i][j] + 1) % inf;
            if (s[i] == t[j])
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % inf;
            dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % inf;
        }
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum = (sum + dp[i][m]) % inf;
    cout << sum << endl;
    return 0;
}