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
const int N = 1e6 + 10;

ll a[N], b[N];

char s1[N], t1[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s, t;
    scanf("%s", s1);
    s = s1;
    scanf("%s", t1);
    t = t1;
    //cin >> s >> t;

    fr(i, t.size())
        b[t[i]]++;
    ll q = 0;
    fr(i, s.size())
        if (s[i] == '?')
            q++;
        else
            a[s[i]]++;

    ll c1 = -1;
    for (ll i = MAX; i >= 0; i--) {
        ll cnt = 0;
        frab(j, 'a', 'z' + 1)
            cnt += max((ll)0, (i * b[j] - a[j]));
        if (cnt <= q) {
            c1 = i;
            break;
        }
    }

    //cout << c1 << endl;

    string t2;
    frab(j, 'a', 'z' + 1)
        fr(i, (c1 * b[j] - a[j]))
            t2 += (char)j;
    while (t2.size() < q)
        t2 += 'a';

    int cur = 0;
    fr(i,s.size())
        if (s[i] == '?')
            s[i] = t2[cur++];
    cout << s;

}