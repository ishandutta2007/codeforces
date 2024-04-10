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
const int N = 2e6 + 10;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;
const int ALF = 26;

int n, k, m;
char s[N];
int dp[ALF];

void read() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    m = strlen(s);
}

bool use[N];
vector < char > g;

void solve() {
    for (int i = m - 1; i >= 0; i--) {
        int id = s[i] - 'a';
        if (use[id] == 0) {
            use[id] = 1;
            g.pb(s[i]);
        }
    } 
    for (int i = 0; i < k; i++)
        if (!use[i])
            g.pb('a' + i);
    reverse(g.begin(), g.end());
    assert((int)g.size() == k);
    for (int i = 0; i < n; i++)
        s[m + i] = g[i % k];



    int len = strlen(s);
    int sum = 1;
    assert(len == n + m);
    for (int i = 0; i < len; i++) {
        int id = s[i] - 'a';
        int oldSum = sum;
        sum = (sum * 1ll * 2 - dp[id] + MOD) % MOD;
        dp[id] = oldSum;
    }
    printf("%d\n", sum);
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