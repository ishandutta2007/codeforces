#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;


int main() {
    //freopen("sweets.in", "r", stdin);
    string s, t;
    cin >> s>> t;
    int ans = 0;
    frab(r, (int)t.size() - 1, s.size()) {
        int l = r - (int)t.size() + 1;
        if (s.substr(l, t.size()) == t) {
            s[r] = '#';
            ans++;
        }
    }
    cout << ans;

}