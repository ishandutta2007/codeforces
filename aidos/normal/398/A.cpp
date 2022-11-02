#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
ll calc_cost(ll a, ll b) {
    ll x = n;
    ll y = k/b;
    return (n - a + 1) * (n - a + 1) + 1 * (a-1) - y * y * (b - k % b) - (y + 1) * (y + 1) * (k % b);
}
void out(ll a, ll b) {
    vector<string> A, B;
    for(int i = 1; i < a; i++) {
        A.emplace_back("o");
    }

    string cur = "";
    for(int i = 1; i <= n - a + 1; i++) {
        cur += "o";
    }
    A.emplace_back(cur);
    for(int i = 0; i < b; i++) {
        int x = k / (b - i);
        cur = "";
        k-=x;
        for(int j = 0; j < x; j++) cur += "x";
        B.emplace_back(cur);
    }
    if(A.size() < B.size()) swap(A, B);
    for(int i = 0; i < A.size(); i++ ){
        cout << A[i];
        if(i < B.size()) cout << B[i];
    }
}
void solve() {
    cin >> n >> k;
    if(n == 0 || k == 0) {
        string ans = "";
        for(int i = 0; i < n; i++) ans += "o";
        for(int i = 0; i < k; i++) ans += "x";
        cout << n * 1ll * n - k * 1ll * k << "\n"<<ans<<"\n";
        return;
    }
    ll ans = -(1ll<<60);
    for(int i = 1; i <= n; i++) {
        if(i <= k) ans = max(ans, calc_cost(i, i));
        if(i + 1 <= k) ans = max(ans, calc_cost(i, i + 1));
        if(i - 1 >= 1) ans = max(ans, calc_cost(i, i - 1));
    }
    cout << ans << "\n";
    for(int i = 1; i <= n; i++) {
        if(i <= k && ans == calc_cost(i, i)) {
            out(i, i);
            return;
        }
        if(i + 1 <= k && ans == calc_cost(i, i + 1)) {
            out(i, i + 1);
            return;
        }
        if(i - 1 >= 1 && ans == calc_cost(i, i - 1)) {
            out(i, i - 1);
            return;
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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