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
int n, m;
int k;
string s;
int T;

int sz = 0;
int u[maxn];
int cnt[26];
void dfs(int v) {
    if(v < 0 || v >= n || u[v] == T) return;
    u[v] = T;
    cnt[s[v] - 'a']++;
    dfs(v - k);
    dfs(v + k);
    dfs( n - v - 1);
}
void solve() {
    cin >> n >> k;
    cin >> s;
    int ans = 0;
    T++;
    for(int i = 0; i < n; i++) {
        if(u[i]!=T) {
            dfs(i);
            int sum = 0;
            int mx = 0;
            for(int j = 0 ; j < 26; j++) {
                if(cnt[j] > mx) {
                    mx = cnt[j];
                }
                sum += cnt[j];
                cnt[j] = 0;
            }
            ans += sum - mx;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}