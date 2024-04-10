#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
string s;
int b[maxn];
int c[maxn];
void solve() {
    cin >> s;
    n = s.size();

    for(int i = 1; i <= n; i++) {
        a[i] = a[i-1];
        if(s[i-1] == '+') a[i]++;
        else a[i]--;
        b[i] = min(b[i-1], a[i]);
    }
    long long ans = 0;
    int x = b[n];
    if(x == 0) {
        cout << n << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        ans += b[i-1] - x + 1;
    }
    cout << ans << "\n";
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