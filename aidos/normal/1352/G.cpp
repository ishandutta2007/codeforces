#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n;
int a[maxn];
void solve() {
    cin >> n;
    if(n <= 3) {
        cout << -1 << "\n";
        return;
    }
    vector<int> ans = {2, 4, 1, 3};
    for(int i = 5; i <= n; ) {
        if((n+1) % 4 != (i % 4)) {
            if(ans[0] < ans.back()) ans.insert(ans.begin(), i);
            else ans.emplace_back(i);
            i++;
        }else {
            ans.push_back(i+1);
            ans.push_back(i+3);
            ans.push_back(i);
            ans.push_back(i+2);
            i += 4;
        }
    }
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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