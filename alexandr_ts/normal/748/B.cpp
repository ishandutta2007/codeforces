#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4 + 1;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

bool a[N];

int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    set <pair <char, char> > st;
    fr(i, s.size())
        if (s[i] != t[i]) {
            if (a[s[i]] || a[t[i]]) {
                if (!st.count(mp(min(s[i], t[i]), max(s[i], t[i])))) {
                    cout << -1;
                    return 0;
                }
            }
            st.insert(mp(min(s[i], t[i]), max(s[i], t[i])));
            a[s[i]] = a[t[i]] = true;
        }
    fr(i, s.size())
        if (s[i] == t[i] && a[s[i]]) {
            cout << -1;
            return 0;
        }
    cout << st.size() << endl;
    for (auto it: st)
        cout << it.first << " " << it.second << endl;

}