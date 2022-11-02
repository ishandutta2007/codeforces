#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = 998244353 ;
const int inf = (1<<30) - 1;
int n, A;
ll a[maxn];
ll c[maxn];
ll L[maxn];
ll R[maxn];
ll sum[maxn];
ll suml[maxn];
ll sqr(ll x) {
    return x * x;
}
void solve() {
    cin >> n >> A;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
        c[i] = A - c[i];
        ans = max(ans, c[i]);
    }
    vector<int> st;
    for(int i = 1; i < n; i++) {
        ll cur_sum = 0;
        ll max_sum = 0;
        while(st.size() > 0 && sqr(a[st.back()] - a[st.back() - 1]) <= sqr(a[i] - a[i-1])) {
            max_sum = max(suml[st.size()] + cur_sum, max_sum);
            cur_sum += sum[st.size()];
            st.pop_back();
        }
        st.emplace_back(i);
        sum[st.size()] = cur_sum + c[i-1];
        suml[st.size()] = max(max_sum + c[i-1], c[i-1]);
        L[i] = max_sum + c[i-1];
    }
    st.clear();
    for(int i = n-1; i > 0; i--) {
        ll cur_sum = 0;
        ll max_sum = 0;
        while(st.size() > 0 && sqr(a[st.back()] - a[st.back() - 1]) <= sqr(a[i] - a[i-1])) {
            max_sum = max(suml[st.size()] + cur_sum, max_sum);
            cur_sum += sum[st.size()];
            st.pop_back();
        }
        st.emplace_back(i);
        sum[st.size()] = cur_sum + c[i];
        suml[st.size()] = max(max_sum + c[i], c[i]);
        R[i] = max_sum + c[i];
    }
    for(int i = 1; i < n; i++) {
        ans = max(ans, L[i] + R[i] - sqr(a[i] - a[i-1]));
    }
    cout << ans << "\n";
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