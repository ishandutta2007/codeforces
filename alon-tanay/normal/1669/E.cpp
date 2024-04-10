#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<ll,ll>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> cntL(26);
        vector<ll> cntR(26);
        vector<ll> cnt(26*26);
        ll res = 0;
        for(ll i = 0; i < n; i ++) {
            char c1, c2;
            cin >> c1 >> c2;
            ll a = c1-'a';
            ll b = c2-'a';
            res += cntL[a] + cntR[b] - 2 * cnt[a*26+b];
            cntL[a] ++;
            cntR[b] ++;
            cnt[a*26+b] ++;
        }
        cout << res << "\n";
    }
    return 0;
}