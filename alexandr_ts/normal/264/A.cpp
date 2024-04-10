#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e2 + 1;
const ll INF = 3e18;
const ll MAX = 1e6 + 1;
const ll ALPH = 300;
const ld EPS = 1e-12;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector <int> l, r;
    l.reserve(s.size());
    r.reserve(s.size());
    fr(i, s.size())
        if (s[i] == 'l')
            l.pb(i + 1);
        else
            r.pb(i + 1);
    reverse(l.begin(), l.end());
    fr(i, r.size())
        cout << r[i] << "\n";
    fr(i, l.size())
        cout << l[i] << "\n";


}