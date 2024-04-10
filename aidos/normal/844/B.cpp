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
int a[maxn];
int b[maxn];
int st[maxn];
void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            a[i] += x;
            b[j] += x;
        }
    }
    ll ans = -n * k;
    for(int i = 0;i<n; i++) {
        ans += (1ll<<a[i]) - 1;
        ans += (1ll<<(k - a[i])) - 1;
    }
    for(int i = 0;i<k; i++) {
        ans += (1ll<<b[i]) - 1;
        ans += (1ll<<(n - b[i])) - 1;
    }
    cout<<ans<<"\n";
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