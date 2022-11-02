#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
string s;
void solve() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '0' || i + 1 == s.size()) {
            cout << s.substr(0, i) << s.substr(i + 1) << "\n";
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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