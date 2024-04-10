#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
string s;
int x, y;

pii pref[maxn];
int ok(int len) {
    int a = 0, b = 0;
    for(int i = n - 1; i >= len - 1; i--) {
        pii z = pref[i - len + 1];
        if(abs(z.first + a - x) + abs(z.second + b - y) <= len) {
            return 1;
        }
        if(s[i] == 'U') b++;
        if(s[i] == 'D') b--;
        if(s[i] == 'L') a--;
        if(s[i] == 'R') a++;
    }
    return 0;
}
void solve(){
    cin >> n >> s >> x >> y;
    int a = 0, b = 0;
    for(int i = 0; i < s.size(); i++) {
        pref[i] = make_pair(a, b);
        if(s[i] == 'U') b++;
        if(s[i] == 'D') b--;
        if(s[i] == 'L') a--;
        if(s[i] == 'R') a++;
    }
    pref[n] = make_pair(a, b);
    int len = abs(x) + abs(y);
    if(n % 2 != (len) % 2 || n < len) {
        cout << -1 << "\n";
        return;
    }
    if(a == x && b == y) {
        cout << 0 << "\n";
        return;
    }
    int l = 1, r = n, res;
    while(l <= r) {
        int mid = (l + r)/2;
        if(ok(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res << "\n";
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