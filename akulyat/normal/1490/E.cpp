#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<pll> v;
bool viv = false;


void solve() {
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i.F;
    for (int i = 0; i < n; i++)
        v[i].S = i;
    sort(v.begin(), v.end());

    int lst = -1;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].F > sum)
            lst = i - 1;
        sum += v[i].F;
    }

    vector<int> ans;
    for (int i = lst + 1; i < n; i++)
        ans.push_back(v[i].S + 1);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    cin >> t;
    while (t--)
        solve();

    return 0;
}