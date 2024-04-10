#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
string s;
int get(string s) {
    int cur = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'K' && s[i-1] == 'V') cur++;
    }
    return cur;
}
void solve() {
    cin >> s;
    int ans = get(s);
    for(int i = 0; i < s.size(); i++) {
        string t = s;
        t[i] = 'K';
        ans = max(ans, get(t));
        t[i] = 'V';
        ans = max(ans, get(t));
    }
    cout << ans << "\n";
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