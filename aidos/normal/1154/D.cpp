#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, x, y;
int a[maxn];
int ok(int len) {
    if(len <= x + y) return 1;
    int need = x + y - len;
    int cur_x = x;
    int cur_y = y;
    for(int i = 1; i <= len; i++) {
        if(cur_x == 0 && cur_y == 0) return 0;
        if(a[i] == 1) {
            if(cur_y == 0 || (cur_x > 0 && cur_y < y)) {
                cur_x--;
                cur_y++;
            } else {
                cur_y--;
            }
        } else if(cur_y > 0) {
            cur_y--;
        } else {
            cur_x--;
        }
    }
    return 1;
}
void solve() {
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n, res;
    while(l <= r) {
        int mid = (l + r)/2;
        if(ok(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid-1;
        }
    }
    cout << res << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
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