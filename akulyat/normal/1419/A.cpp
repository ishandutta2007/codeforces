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
string s;
vector<ll> v;
bool viv = false;


void solve() {
    cin >> n;
    cin >> s;
    v.clear();
    for (auto &i : s)
        v.push_back((i - '0') & 1);
    vector<int> cnt(2, 0);
    if (n & 1) {
        for (int i = 0; i < n; i += 2)
            cnt[v[i]]++;
        if (cnt[1])
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    } else {
        for (int i = 1; i < n; i += 2)
            cnt[v[i]]++;        
        if (cnt[0])
            cout << 2 << '\n';
        else
            cout << 1 << '\n';
    }

}

int main() {
    // viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    cin >> t;
    while (t--)
        solve();

    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}