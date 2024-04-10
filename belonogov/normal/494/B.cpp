#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define next nexttt


#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 2e5 + 100;
const int INF = 1e9;
const long long MOD = 1e9 + 7;


char s[N];
char t[N];
int n, m;
int z[N];
int p[N];
long long dp[N][2];
int next[N];

void read() {
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(s);
    m = strlen(t);
    t[m] = '#';
    for (int i = 0; i < n; i++)
        t[m + 1 + i] = s[i];
}

void zF() {
    int l = 0; 
    int r = 0;
    int len = n + m + 1;
    for (int i = 1; i < len; i++) {
        if (r > i) {
            z[i] = min(r - i, z[i - l]);
        }
        for (; i + z[i] < len && t[i + z[i]] == t[z[i]]; z[i]++);
        if (i + z[i] >= r) {
            l = i;
            r = i + z[i];
        }
    }
}

void add(long long & a, long long b) {
    a = (a + b) % MOD;
}

void solve() {
    zF();
    for (int i = 0; i < n; i++)
        if (z[i + m + 1] == m) 
            p[i] = 1;
    int tmp = -1;    
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] == 1) tmp = i;
        next[i] = tmp;
    }
    //cerr << t << endl;
    //for (int i = 0; i < n + m + 2; i++)
        //cerr << z[i] << " " ;
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << p[i] << " ";
    //cerr << endl;
    
    /// 0 - ready to finish
    //
    /// 1 - ready to start
    dp[0][1] = 1; 
    for (int i = 0; i < n; i++)  {
        if (next[i] != -1)
            add(dp[next[i] + m - 1][0], dp[i][1]);
        add(dp[i + 1][1], dp[i][0]);
        add(dp[i + 1][0], dp[i][0]);
        add(dp[i + 1][1], dp[i][1]);
    }
    //for (int j = 0; j < 2; j++, cerr << endl)
        //for (int i = 0; i <= n; i++)
            //cerr << dp[i][j] << " ";
    long long ans = (dp[n - 1][0] + dp[n - 1][1] - 1 + MOD) % MOD;
    cout << ans << endl;
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}