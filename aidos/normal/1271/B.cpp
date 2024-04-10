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
char rev(char c) {
    if(c == 'W') return 'B';
    return 'W';
}
void can(string t, char c) {
    vector<int> ans;
    for(int i = 0; i + 1 < n; i++) {
        if(t[i] != c) {
            t[i] = rev(t[i]);
            t[i+1] = rev(t[i+1]);
            ans.emplace_back(i+1);
        }
    }
    if(t[n-1] != c) return;
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    exit(0);
}
void solve() {
    cin >> n;
    cin >> s;
    can(s, 'B');
    can(s, 'W');
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}