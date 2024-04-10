#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n;
string s;
void solve() {
    cin >> n >> s;
    int bal = 0, mi = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            bal++;
        } else if(bal == 0){
            mi++;
        } else {
            bal--;
        }
    }
    int cnt = 0;
    if(bal == 2 && mi == 0) {
        int cur = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == ')') {
                cur++;
            } else {
                cnt++;
                if(cur == 0) break;
                cur--;
            }
        }
    } else if(mi == 2 && bal == 0) {
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                cur++;
            } else {
                cnt++;
                if(cur == 0) break;
                cur--;
            }
        }
    }
    cout << cnt << "\n";
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