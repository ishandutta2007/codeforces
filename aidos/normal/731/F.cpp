#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;
string s;
int n, k;
ll cnt[maxn];
ll sum[maxn];
vector<int> d[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        sum[x] += x;
    }
    for(int i = 1; i < maxn; i++) {
        for(int j = i; j < maxn; j+=i) {
            d[j].emplace_back(i);
        }
    }
    for(int i = 1; i < maxn; i++) {
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
    }
    ll ans = 0;
    for(int j = 1; j < maxn; j++) {
        if(cnt[j] == cnt[j-1]) continue;
        ll cur = 0;
        for(int k = j; k < maxn; k += j) {
            cur += k * (cnt[min(maxn-1, k + j - 1)] - cnt[k-1]);
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
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