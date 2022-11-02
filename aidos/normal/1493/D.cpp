#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 123;
const int mod = 1e9 + 7;

int a[maxn];
int lp[maxn];
int n, q;

ll ans = 1;
set < pair<int, int> > S[maxn];
map<int, int> cnt_pr[maxn];
ll binpow(ll x, ll y) {
    if(y == 0) return 1;
    if(y % 2 == 1) return binpow(x, y-1) * x % mod;
    return binpow(x * x % mod, y/2);
}
void add(int pos, int p, int cnt) {
    if(S[p].size() == n) {
        ans = (ans * binpow(binpow(p, S[p].begin()->first), mod-2)) % mod;
    }
    S[p].erase(make_pair(cnt_pr[p][pos], pos));
    cnt_pr[p][pos] += cnt;
    S[p].insert(make_pair(cnt_pr[p][pos], pos));
    if(S[p].size() == n) {
        ans = (ans * binpow(p, S[p].begin()->first)) % mod;
    }
}

void mul(int pos,int val) {
    while(val > 1) {
        int p = lp[val];
        int cnt = 0;
        while(val % p == 0) {
            val /= p;
            cnt++;
        }
        add(pos, p, cnt);
    }
}
void solve() {
    for(int i = 2; i < maxn; i++) {
        if(lp[i] == 0) {
            for(int j = i; j < maxn; j+= i) {
                if(lp[j] == 0) lp[j] = i;
            }
        }
    }
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        mul(i, x);
    }
    for(int i = 0; i < q; i++) {
        int pos, x;
        cin >> pos >> x;
        mul(pos-1, x);
        cout << ans << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}