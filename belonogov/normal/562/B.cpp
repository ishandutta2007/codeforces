#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";

const int N = 1e6 + 20;
const int INF = 1e9 + 19;

int n;
bool use[N];
int dp[N];


void read() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        use[x] = 1;
        mx = max(mx, x);
    }
    int ans = 0;
    //int cnt = 0;
    for (int i = mx; i >= 1; i--) {
        if (use[i]) {
            dp[i] = 1;
            for (int k = 2; k * i <= mx; k++) {
                dp[i] = max(dp[i], dp[k * i] + 1);
                //cnt++;
            }
            ans = max(dp[i], ans);
        }
    }
    cout << ans << endl;
}

void solve() {


}

void stress() {

}


int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
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