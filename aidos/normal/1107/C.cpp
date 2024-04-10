#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;
string s;
int n, k;
int a[maxn];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0 && s[i] == s[i-1]) continue;
        vector<int> x;
        for(int j = i; j < n; j++) {
            if(s[j] != s[i]) break;
            x.emplace_back(a[j]);
        }
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        for(int j = 0; j < x.size() && j < k; j++) {
            ans += x[j];
        }
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