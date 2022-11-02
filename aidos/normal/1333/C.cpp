#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
int n;

map<ll, int> m;
void solve() {
    m[0] = 0;
    cin >> n;
    ll s = 0;
    int l = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        s += x;
        if(m.count(s))
            l = max(l, m[s]+1);
        m[s] = i;
        ans += i - l;
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}