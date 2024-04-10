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
vector<string> m;
vector<vector<ll>> b;
vector<ll> col;
vector<bool> used;
vector<vector<ll>> reb;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    for (auto buk : reb[v])
        if (!used[buk]) {
            used[buk] = true;
            for (auto s : b[buk])
                if (col[s] == -1)
                    DFS(s, c);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    reb.resize(n);
    b.resize(26);
    for (i = 0; i < n; i++) {
        string a;
        cin >> a;
        m.push_back(a);
        vector<bool> was(26, false);
        for (auto j : a) {
            if (!was[j - 'a'])
                b[j - 'a'].push_back(i), was[j - 'a'] = true, reb[i].push_back(j - 'a');
        }
    }
    used.resize(26, false);
    ll tc = 0;
    col.resize(n, -1);
    for (ll i = 0; i < n; i++)
        if (col[i] == -1)
            DFS(i, tc), tc++;

    cout << tc << endl;



    return 0;
}