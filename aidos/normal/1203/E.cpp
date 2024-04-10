#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 998244353 ;
int n, k = 200200;
int cnt[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int i = 1; i < k; i++) {
        if(cnt[i-1] > 0) {
            cnt[i-1]--;
            ans++;
            continue;
        }
        if(cnt[i] > 0) {
            cnt[i]--;
            ans++;
            continue;
        }
        if(cnt[i+1] > 0) {
            cnt[i+1]--;
            ans++;
            continue;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}