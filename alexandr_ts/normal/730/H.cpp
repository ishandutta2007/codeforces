#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e6 + 10;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e5 + 10;

int a[N];
string s[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> s[i];
    set <int> dels;
    fr(i, m) {
        cin >> a[i];
        a[i]--;
        dels.insert(a[i]);
    }
    string pat = s[a[0]];
    frab(i, 1, m) {
        string t = s[a[i]];
        if (t.size() != pat.size()) {
            cout << "No";
            return 0;
        }
        int l = t.size();
        fr(j, l)
            if (t[j] != pat[j])
                pat[j] = '?';
    }

    fr(i, n)
        if (!dels.count(i)) {
            bool ok = true;
            if (s[i].size() != pat.size()) continue;
            fr(j, s[i].size())
                if (s[i][j] != pat[j] && pat[j] != '?')
                    ok = false;
            if (ok) {
                cout << "No";
                return 0;
            }
        }
    cout << "Yes" << endl << pat;


}