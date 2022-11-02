#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
int m;
int q;
string s, t;
int a[maxn];
int sum[maxn];
void solve(){
    cin >> n >> m >> q >> s >> t;
    for(int i = 0; i < n; i++) {
        a[i + 1] = 1;
        for(int j = 0; j < m; j++) {
            if(i + j == n) {
                a[i + 1] = 0;
                break;
            }
            if(s[i + j] != t[j]) {
                a[i + 1] = 0;
                break;
            }
        }
        sum[i + 1] = sum[i] + a[i + 1];
    }
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        if(l + m - 1 <= r) {
            ans = sum[r-m + 1] - sum[l-1];
        }
        cout << ans << "\n";
    }
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