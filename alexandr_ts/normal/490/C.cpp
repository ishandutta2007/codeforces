#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e5 + 10;
const ll INF = 2e9 + 10;
const ll N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll pref[N], suf[N], pows[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    pows[0] = 1;
    frab(i, 1, s.size() + 1)
        pows[i] = pows[i - 1] * 10 % b;
    pref[0] = (s[0] - '0') % a;
    frab(i, 1, s.size()) {
        pref[i] = (pref[i - 1] * 10 + s[i] - '0') % a;
    }
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        suf[i] = (suf[i + 1] + pows[(int)s.size() - i - 1] * (s[i] - '0')) % b;
    }
    frab(i, 1, s.size()) {
        if (s[i] == '0') continue;
        if (pref[i - 1] == 0 && suf[i] == 0) {
            cout << "YES" << endl << s.substr(0, i) << endl << s.substr(i, (int)s.size() - i) << endl;
            return 0;
        }
    }
    cout << "NO";
}