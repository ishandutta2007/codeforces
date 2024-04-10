#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
ll n, k, s;
void solve() {
    cin >> n >> k >> s;
    if(k*(n-1) < s || k > s) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<ll> ans;
    for(int i = 0; i < k; i++) {
        ll cur = s/(k-i);
        ans.emplace_back(cur);
        s -= cur;
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    ll cur=1;
    for(int i = 0; i < k; i++) {
        if(i & 1) cur -= ans[i];
        else cur += ans[i];
        cout << cur << " ";
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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