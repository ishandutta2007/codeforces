#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int mod = 1000000007;
const int R = 1 << 20;
int t[R*2];
int sum(int ql, int qr, int node = 1, int nl = 0, int nr = R){
    if(ql <= nl && nr <= qr)
        return t[node];
    if(qr <= nl || nr <= ql)
        return 0;
    int nm = (nl+nr)/2;
    return (sum(ql, qr, node*2, nl, nm)+sum(ql, qr, node*2+1, nm, nr))%mod;
}
void update(int pos, int val){
    pos += R;
    t[pos] += val;
    t[pos] %= mod;
    for(pos /= 2; pos != 0; pos /= 2)
        t[pos] = t[pos*2]+t[pos*2+1], t[pos] %= mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = a[i]*(sum(0, a[i]+1)+1)%mod;
        k -= sum(a[i], a[i]+1);
        k = (k+mod)%mod;
        ans += k;
        update(a[i], k);
        ans %= mod;
    }
    cout << ans;
    return 0;
}