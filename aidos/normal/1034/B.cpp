#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
ll n, m;
vector<pii> a, b;
int dp[11][1<<10];
void solve() {
    cin >> n >> m;
    if(n > m) {
        swap(n, m);
    }
    if(n >= 3) {
        ll cur = n * m;
        cur /= 2;
        cout << cur*2<< "\n";
        return;
    }
    if(n == 1){
        ll cur = m/6 * 6;
        m -= cur;
        if(m > 3) cur+=2*m-6;
        cout<<cur << "\n";
        return;
    }
    if(m > 10) {
        cout << 2 * m << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) % 2 == 0) a.push_back(make_pair(i, j));
            else b.push_back(make_pair(i, j));
        }
    }
    dp[0][0] = 1;
    int A = b.size();
    for(int i = 0; i < a.size(); i++) {
        for(int mask = 0; mask < (1<<A); mask++) {
            if(dp[i][mask] == 0) continue;
            dp[i+1][mask] = 1;
            for(int j = 0; j < A; j++) {
                if(mask & (1<<j)) continue;
                if(abs(a[i].first - b[j].first) + abs(a[i].second-b[j].second) != 3) continue;
                dp[i+1][mask|(1<<j)] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=0; i < (1<<A); i++) {
        if(dp[a.size()][i]) ans = max(ans, __builtin_popcount(i));
    }
    cout << 2*ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}