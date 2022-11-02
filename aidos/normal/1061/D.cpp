#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
ll x, y;
int l[maxn];
int r[maxn];
ll cnt[maxn];
bool bad(ll en, ll cur) {
    if((cur - en) * y >= x) return 1;
    return 0;
}
void solve(){
    cin >> n >> x >> y;
    vector<ll> d;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        for(int j = -1; j <= 1; j++) {
            d.emplace_back(l[i] + j);
            d.emplace_back(r[i] + j);
        }
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    m = d.size();
    for(int i = 0; i < n; i++) {
        int posl = lower_bound(d.begin(), d.end(), l[i]) - d.begin();
        cnt[posl]++;
        int posr = lower_bound(d.begin(), d.end(), r[i]) - d.begin();
        cnt[posr + 1]--;
    }
    multiset<pii> S;
    ll ans = 0;
    for(int i = 1; i < m; i++) {
        cnt[i] += cnt[i-1];
        while(S.size() > 0 && bad(S.begin()->first, d[i])) {
            S.erase(S.begin());
        }
        if(cnt[i] > 0) {
            ll h = cnt[i];
            while(h > 0 && S.size() > 0) {
                pii t = *(--S.end());
                if(t.second <= h) {
                    S.erase(--S.end());
                    h -= t.second;
                    ans = (ans + t.second * (d[i] - t.first) % mod * y) % mod;
                } else {
                    S.erase(--S.end());
                    t.second -= h;
                    ans = (ans + h * (d[i] - t.first) % mod * y) % mod;
                    h = 0;
                    S.insert(t);
                }
            }
            ans = (ans + h * x) % mod;
            ans = (ans + (d[i + 1] - d[i] - 1) * cnt[i] % mod * y) % mod;
            S.insert(make_pair(d[i+1] - 1, cnt[i]));
        }

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