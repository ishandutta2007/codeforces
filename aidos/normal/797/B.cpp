#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
int u[1<<22];
int cnt;
int was[1<<22];
void dfs(int mask) {
    if(was[mask]) return;
    was[mask] = 1;
    for(int i = 0; i < n; i++) {
        if(mask & (1<<i)) {
            dfs(mask^(1<<i));
        }
    }
    if(u[mask]) {
        dfs(mask^((1<<n) - 1));
    }
}
void solve() {
    cin >> n;
    vector<int> A, B;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x % 2 == 0) {
            sum += max(x, 0);
        } else if(x > 0) {
            A.emplace_back(x);
            sum += x;
        } else {
            A.emplace_back(-x);
        }
    }
    if(sum % 2 == 1) {
        cout << sum << "\n";
        return;
    }
    cout << sum - *min_element(A.begin(), A.end()) << "\n";
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