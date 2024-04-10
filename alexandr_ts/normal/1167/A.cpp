#include <bits/stdc++.h>


#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ll INF = 1e15 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;


void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    while (s.size() && s[0] != '8')
        s.erase(s.begin());
    if (s.size() >= 11)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}