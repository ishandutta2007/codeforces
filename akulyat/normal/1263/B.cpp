#include<bits/stdc++.h>

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
vector<string> m;
map<string, ll> all;
bool viv = false;

void solve() {
    cin >> n;
    m.clear();
    all.clear();
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        m.push_back(s);
        all[s]++;
    }
    vector<string> ans;
    ll res = 0;
    map<string, ll> was;
    for (auto i : m) {
        if (all[i] == 1 || was[i] == 0)
            ans.push_back(i), was[i]++;
        else {
            bool need = true;
            for (ll j = 0; j < 4; j++) {
                for (ll z = 0; z < 10; z++) {
                    auto st = i;
                    st[j] = char('0' + z);
                    if (all[st] == 0 && need) {
                        all[st] = 1;
                        was[st]++;
                        ans.push_back(st);
                        need = false;
                    }
                }
            }
            res++;
        }
    }
    cout << res << endl;
    for (auto i : ans)
        cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}