#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)1000200;
const ll inf = (1ll<<50);

string s;
int n,m;
void solve() {
    cin >> n >> m >> s;
    for(int i = 0; i < s.size(); i++) {
        int nn = n;
        int mm = m;
        if(s[i] == 'L') nn++;
        else if(s[i] == 'R') nn--;
        else if(s[i] == 'U') mm--;
        else mm++;
        if(abs(nn) < abs(n)) n = nn;
        if(abs(mm) < abs(m)) m = mm;
    }
    if(n == 0 && m == 0) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}