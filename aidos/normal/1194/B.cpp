#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
string s[maxn];
int a[maxn], b[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < max(n, m); i++) a[i] = 0,b[i] = 0;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') {
                a[i]++;
                b[j]++;
            }
        }
    }
    int ans = n + m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') {
                ans = min(a[i] + b[j] - 1, ans);
            } else {
                ans = min(ans, a[i] + b[j]);
            }
        }
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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