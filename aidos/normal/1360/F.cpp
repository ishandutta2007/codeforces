#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
string s[111];
bool ok(string t) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] != t[j]) cnt++;
        }
        if(cnt > 1) return 0;
    }
    return 1;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 26; j++) {
            string t = s[0];
            t[i] = j + 'a';
            if(ok(t)) {
                cout << t << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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