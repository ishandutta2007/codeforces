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


ll n, i, j;
vector<ll> m;
bool viv = false;

void solve() {
    ll k;
    cin >> k;
    ll z = 10 * sqrt(k + 1) + 20;
    vector<ll> ans;
    set <ll> st;
    ll p = 1;
    bool need = true;
    while (need) {
        ll add = k / p;
        ans.push_back(add);
        if (ans.size() > 10 && abs(ans[ans.size() - 1] - ans[ans.size() - 2]) < 1) {
            need = false;
            for (ll i = 0; i < add; i++)
                ans.push_back(i);
        }
        p++;
    }
    for (auto i : ans)
        st.insert(i);
    cout << st.size() << '\n';
    for (auto i : st)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}