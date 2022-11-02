#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353;
const int inf = (1<<30) - 1;

int n;

int a[maxn];
int dp[maxn][6];
int get(int pos, int last) {
    if(pos == n) return 1;
    int &res = dp[pos][last];
    if(res != -1) return res;
    res = 0;
    for(int i = 1; i <= 5; i++) {
        int can = get(pos + 1, i);
        if(!can) continue;
        if(a[pos] > a[pos-1]&&last < i) {
            res = 1;
        }
        if(a[pos] < a[pos-1] && last > i) {
            res = 1;
        }
        if(a[pos] == a[pos-1] && last != i) {
            res = 1;
        }
    }
    return res;
}
void rec(int pos, int last) {
    if(pos == n) return;
    for(int i = 1; i <= 5; i++) {
        int can = get(pos + 1, i);
        if(!can) continue;
        if(a[pos] > a[pos-1]&&last < i) {
            cout << i << " ";
            rec(pos+1, i);
            return;
        }
        if(a[pos] < a[pos-1] && last > i) {
            cout << i << " ";
            rec(pos+1, i);
            return;
        }
        if(a[pos] == a[pos-1] && last != i) {
            cout << i << " ";
            rec(pos+1, i);
            return;
        }
    }
}
void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= 5; i++) {
        if(get(1, i)) {
            cout << i << " ";
            rec(1, i);
            return;
        }
    }
    cout << -1 << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}