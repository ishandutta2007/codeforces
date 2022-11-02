#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for(int len = 1; len <= n; len++) {
        int ok = 1;
        for(int i = len + 1; i <= n; i++) {
            if(a[i] - a[i-1] != a[i-len] - a[i-len - 1]) ok = 0;
        }
        if(ok) ans.emplace_back(len);
    }
    cout << ans.size() << "\n";

    for(const int &to: ans) cout << to << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}