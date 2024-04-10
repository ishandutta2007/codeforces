#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
string s[maxn];
unordered_map<string, int> id;
void solve() {
    cin >> n >> m;
    id.rehash(n  * n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        id[s[i]] = i;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            string t;
            for(int k = 0; k < m; k++) {
                if(s[i][k] == s[j][k]) t += s[i][k];
                else t += char('S' + 'E' + 'T' - s[i][k] - s[j][k]);
            }
            if(id.count(t) && id[t] > j) ans++;
        }
    }
    cout << ans <<"\n";
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