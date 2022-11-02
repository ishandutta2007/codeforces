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
int a[maxn];
ll sum[maxn];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x < m) {
            a[i] = -1;
        } else if(x > m) {
            a[i] = 1;
        }
        sum[i] = sum[i - 1] + a[i];
    }
    int ind = 0;
    map<int, int> z;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            while(ind < i) {
                z[sum[ind]]++;
                ind++;
            }
        }
        ans += z[sum[i]];
        ans += z[sum[i] - 1];
    }

    cout << ans << "\n";
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