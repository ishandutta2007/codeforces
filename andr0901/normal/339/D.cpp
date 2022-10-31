#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <int> tr;

void upd(int v, bool f) {
    if (!v)
        return;
    if (f)
        tr[v] = tr[2 * v] | tr[2 * v + 1];
    else 
        tr[v] = tr[2 * v] ^ tr[2 * v + 1];
    upd(v / 2, !f);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int _n, m;
    cin >> _n >> m;
    int n = (1 << _n);
    tr.resize(2 * n);
    forn (i, 0, n) 
        cin >> tr[i + n], upd((i + n) / 2, 1);
    while (m --> 0) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        tr[idx + n] = val;
        upd((idx + n) / 2, 1);
        cout << tr[1] << "\n";
    }
    return 0;
}