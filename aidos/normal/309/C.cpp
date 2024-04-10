#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int cnta[maxn];
int cntb[maxn];
ll a[maxn];
ll b[maxn];
bool can(int x) {
    for(int i = 0; i < 30; i++) a[i] = cnta[i];
    for(int i = 0; i < 30; i++) {
        b[i] = min(cntb[i], x);
        x -= b[i];
    }
    for(int i = 29; i >= 0; i--) {
        a[i] += 2 * a[i + 1];
        if(b[i] > a[i]) {
            return false;
        }
        a[i] -= b[i];
    }
    return true;
}
void solve(){
    cin>> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < 30; j++) {
            if(x & (1<<j)) cnta[j]++;
        }
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cntb[x]++;
    }
    int l = 1, r = m;
    int res = 0;
    while(l <= r) {
        int mid = (l + r)/2;
        if(can(mid)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
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