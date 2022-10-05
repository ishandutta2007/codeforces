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
vector<ll> v;
bool viv = false;


void solve() {
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i, i--;

    vector<int> ans_mn(n, -1), ans_mx(n, -1);

    deque<int> l_mx, l_mn;
    set<int> l;
    for (int i = 0; i < n; i++) 
        l.insert(i);

    for (int i = 0; i < n; i++) {
        if (!i || v[i] != v[i - 1]) {
            ans_mx[i] = ans_mn[i] = v[i];
            l.erase(v[i]);
        }
    }

    for (auto i : l) {
        l_mx.push_back(i);
        l_mn.push_back(i);
    }

    for (int j = 0; j < n; j++) {
        if (ans_mn[j] == -1) {
            if (viv) {
                cout << "\tSEE: \n";
                cout << "\t\t";
                for (auto i : ans_mn)
                    cout << 1 + i << ' ';
                cout << '\n';
                cout << "\t\t";
                for (auto i : ans_mx)
                    cout << 1 + i << ' ';
                cout << '\n';
                cout << endl;
            }
            ans_mn[j] = l_mn.front();
            l_mn.pop_front();

            int see = v[j];
            auto z = l.lower_bound(see);
            assert(z != l.begin());
            z--;
            int val = *z;
            ans_mx[j] = val;
            l.erase(val);
        }
    }
    for (auto i : ans_mn)
        cout << 1 + i << ' ';
    cout << '\n';
    for (auto i : ans_mx)
        cout << 1 + i << ' ';
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