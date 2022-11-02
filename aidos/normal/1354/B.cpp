#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, k;
string s;
int la[5];
void solve() {
    int ans = 0;
    cin >> s;
    for(int i = 1; i <= 3; i++) la[i] = -1;
    for(int i = 0; i < s.size(); i++) {
        la[s[i] - '0'] = i;
        int mi = s.size();
        int mx = -1;
        for(int j = 1; j <= 3; j++) {
            mi = min(mi, la[j]);
            mx = max(mx, la[j]);
        }
        if(mi == -1) continue;
        if(ans == 0) ans = mx - mi + 1;
        else ans = min(ans, mx - mi + 1);
    }
    cout << ans << "\n";

}

int main() {
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