#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector< pair<int, pii > > ans;
    for(int i = 2; i <= n; i++) {
        if(a[i] % i > 0) {
            int x = i - a[i] % i;
            ans.emplace_back(make_pair(1, make_pair(i, x)));
            a[1] -= x;
            a[i] += x;
        }
        ans.emplace_back(make_pair(i, make_pair(1, a[i]/i)));
        a[1] += a[i];
        a[i] = 0;
    }
    if(a[1] % n > 0) {
        cout << -1 << "\n";
        return;
    }
    for(int i = 2; i <= n; i++) {
        ans.emplace_back(make_pair(1, make_pair(i, a[1]/n)));
    }
    cout << ans.size() << "\n";
    for(auto x: ans) {
        cout << x.first << " " << x.second.first << " "<<x.second.second << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}