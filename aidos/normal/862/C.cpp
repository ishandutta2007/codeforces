#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, x;

void solve() {
    cin >> n >> x;
    if(x == 0) {
        if(n == 2) {
            cout << "NO\n";
            return;
        }
    }
    vector<int> ans;
    ans.push_back(x);
    n--;
    if(n % 2 == 1) {
        ans.push_back(0);
        n--;
    }
    if(n % 4 == 2) {
        ans.push_back((1<<17) + (1<<18));
        ans.push_back((1<<17));
        ans[0] += (1<<18);
        n -= 2;
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        ans.push_back((1<<19) - 1 - i);
    }

    if(x == 0 && ans.size() > 1 && ans[1] == 0 && ans[0] == 0) {
        ans[0] ^= 1<<18;
        ans[2] ^= 1<<18;
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    //cout << ans << "\n";
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