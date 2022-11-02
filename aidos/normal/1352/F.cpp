#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int x, y, z;
void solve() {
    cin >> x >> y >> z;
    string ans;
    if(y > 0) {
        ans = "0";
        for(int i = 0; i < x; i++) ans += "0";
        ans += "1";
        for(int i = 0; i < z; i++) ans += "1";
        y--;
        for(int i = 0; i < y; i++) {
            if(ans.back() == '0') ans += '1';
            else ans += '0';
        }
    } else if(x > 0){
        for(int i = 0; i < x + 1; i++)ans += '0';
    }else {
        for(int i = 0; i < z + 1; i++)ans += '1';
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
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}