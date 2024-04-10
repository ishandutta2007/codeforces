#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, k;
vector<ll> m;
string s;
bool viv = false;

void solve() {
    cin >> n >> k;
    cin >> s;
    ll on = 0;
    string tie, head;
    ll sh = -1;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (k >= i - on) {
                k -= (i - on);
//                cout << "need " << i - on << ' ' << i << ' ' << on  << '\n';
                head += '0';
            } else {
                if (!k)
                    tie += '0';
                else {
                    sh = i - on - k;
                    k = 0;
                }
            }
        on++;
        } else {
            tie += '1';
        }
    }
    string ans;
    ans += head;
    if (sh == -1)
        ans += tie;
    else {
//        cout << "______ " << head << ' ' << sh << ' ' << tie << '\n';
        for (ll i = 0; i < sh; i++)
            ans += tie[i];
        ans += '0';
        for (ll i = sh; i < tie.size(); i++)
            ans += tie[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}