#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
string s;
int calc(char c) {
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        cnt += s[i] == c;
    }
    int ans = cnt;
    for(int i = 0; i < s.size(); i++) {
        cnt -= s[i] == c;
        cnt += s[i] != c;
        ans = min(ans, cnt);
    }
    return ans;
}
void solve() {
    cin >> s;
    cout << min(calc('0'), calc('1')) << "\n";
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