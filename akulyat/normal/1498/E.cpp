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

bool ask(int u, int v) {
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    string res;
    cin >> res;
    return (res == "Yes");
}

void say(int u = -1, int v = -1) {
    cout << "! " << u + 1 << ' ' << v + 1 << endl;
    exit(0);
}

void solve() {
    cin >> n;
    v.resize(n);
    for (auto &i : v) {
        cin >> i.F;
    }
    for (int i = 0; i < n; i++)
        v[i].S = i;
    sort(v.begin(), v.end());

    vector<pair<int, pii>> tos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            tos.push_back({v[i].F - v[j].F, {v[i].S, v[j].S}});
        }
    }
    sort(tos.rbegin(), tos.rend());

    for (auto p : tos) {
        if (ask(p.S.F, p.S.S)) 
            say(p.S.F, p.S.S);
    }
    say();
}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    // cin >> t;
    while (t--)
        solve();

    return 0;
}