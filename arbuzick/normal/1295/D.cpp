#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int gsd(int a, int b){
    while(b > 0)
        a %= b, swap(a, b);
    return a;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, m;
        cin >> a >> m;
        int g = gsd(a, m);
        int n = m/g;
        vector<pair<int, int>> p;
        for (int i = 2; i * i <= n; ++i) {
            int k = 1;
            while (n % i == 0) {
                k *= i;
                n /= i;
            }
            p.push_back({k, k/i});
        }
        if (n > 1)
            p.push_back({n, 1});
        int ans = 1;
        for (int i = 0; i < p.size(); ++i) {
           ans *= (p[i].first-p[i].second);
        }
        cout << ans << '\n';
    }
    return 0;
}