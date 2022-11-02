#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
int d[maxn];
int h[maxn];
void solve() {
    cin >> n >> m;
    int ans = 0;
    int mx = 0;
    int dif = 0;
    for(int i = 0; i < n; i++) {
        cin >> d[i] >> h[i];
        mx = max(d[i], mx);
        dif = max(dif, d[i] - h[i]);
    }
    m -= mx;
    if(m <= 0) {
        cout << 1 << "\n";
        return;
    }
    if(dif==0) {
        cout << -1 << "\n";
        return;
    }
    cout << (m + dif - 1)/dif + 1 << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}