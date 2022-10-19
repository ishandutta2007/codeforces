#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, c;
        cin >> n >> p >> c;
        string s;
        cin >> s;
        vector<int> k(c), k2(c);
        for (int i = p-1; i < n; ++i)
            k[i%c] += s[i]-'0', k2[i%c]++;
        int x, y;
        cin >> x >> y;
        int ans = n*x;
        int pos = (p-1)%c;
        for (int i = p-1; i < n; ++i) {
            int ans1 = y*(i-p+1)+(k2[pos]-k[pos])*x;
            k2[i%c]--;
            k[i%c] -= (s[i]-'0');
            pos++;
            pos = (pos+c)%c;
            ans = min(ans, ans1);
        }
        cout << ans << '\n';
    }
    return 0;
}