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
const int N = 77;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;
const int T = 20;

int n;
char s[N];
int dp[N][1 << T];

void read() {
    scanf("%d", &n); 
    scanf("%s", s);
    //int cnt = 0;
    //for (int i = 1; i <= 20; i++) {
        //int x = i;
        //for (; x > 0; x /= 2, cnt++);
    //}
    //cout << cnt << endl;
}

void upd(int & a, int b) {
    a = (a + b) % MOD;
}

void solve() {
    for (int i = 0; i < n; i++) 
        dp[i][0] = 1;   

    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << T); mask++) {
            int x = 0; 
            if (dp[i][mask] == 0) continue;
            for (int len = 1; len + i <= n; len++) {
                x *= 2;
                if (s[len + i - 1] == '1')
                    x++;
                if (x >= T) break;
                //db(dp[i][mask]);
                if (x > 0) {
                    upd(dp[len + i][mask | pw(x - 1)], dp[i][mask]);
                    //db2(len + i, (mask | pw(x - 1)));
                }
            }
        }
    }
    

    ll answer = 0;
    for (int i = 0; i <= n; i++) 
        for (int j = 1; j <= T; j++) {
            int mask = pw(j) - 1;
            answer = (dp[i][mask] + answer) % MOD;
        }
    cout << answer << endl;
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