#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 3e5 + 100;
const int mod = (int)998244353 ;
int n, m;
int a[maxn][8];
pair<int, int> ans;
bool check(int x) {
    vector<int> pos(1<<m, -1);
    for(int i = 0; i < n; i++) {
        int mask = 0;
        for(int j = 0; j < m; j++) {
            if(x <= a[i][j]) mask |= 1<<j;
        }
        pos[mask] = i;
    }
    for(int i = 0; i < (1<<m); i++) {
        for(int j = 0; j < (1<<m); j++) {
            if((i|j) == (1<<m) - 1) {
                if(pos[i] != -1 && pos[j] != -1) {
                    ans = make_pair(pos[i], pos[j]);
                    return true;
                }
            }
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    vector<int> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            d.push_back(a[i][j]);
        }
    }
    sort(d.begin(), d.end());
    int l = 0, r = (int)d.size()-1;
    int res = -1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(check(d[mid])) {
            l = mid+1;
            res = d[mid];
        } else {
            r = mid-1;
        }
    }
    check(res);
    cout << ans.first+1 << " "<<ans.second+1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}