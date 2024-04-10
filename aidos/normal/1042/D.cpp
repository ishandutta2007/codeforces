#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
ll sum[maxn];
ll T;
vector<ll> A;
int t[maxn];
void add(int pos, int val) {
    while(pos < maxn) {
        t[pos] += val;
        pos |= pos + 1;
    }
}
int get(int pos) {
    int res = 0;
    while(pos >= 0) {
        res += t[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}
void upd(ll x) {
    int pos = lower_bound(A.begin(), A.end(), x) - A.begin();
    add(pos, 1);
}
int calc(ll x) {
    int pos = lower_bound(A.begin(), A.end(), x-T) - A.begin();
    return get(maxn-1) - get(pos);
}
void solve(){
    cin >> n >> T;
    A.emplace_back(0);
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        sum[i] = sum[i-1] + x;
        A.emplace_back(sum[i]);
        A.emplace_back(sum[i] - T);
    }
    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    upd(0);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += calc(sum[i]);
        upd(sum[i]);
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