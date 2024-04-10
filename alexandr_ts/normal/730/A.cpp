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

int a[N], b[N];

vector <int> ans3;
vector <pair <int, int> > ans2;

bool solve(int t, int n) {
    ans3.clear();
    ans2.clear();
    fr(i, n)
        b[i] = a[i] - t;
    multiset <pair <int, int> > s;
    fr(i, n)
        if (b[i])
            s.insert(mp(-b[i], i));
    int sum = accumulate(b, b + n, 0ll);
    if (sum % 2) {
        if (s.size() >= 3) {
            auto t1 = *s.begin();
            s.erase(s.begin());
            auto t2 = *s.begin();
            s.erase(s.begin());
            auto t3 = *s.begin();
            s.erase(s.begin());
            ans3.pb(t1.second);
            ans3.pb(t2.second);
            ans3.pb(t3.second);
            t1.first++, t2.first++, t3.first++;
            if (t1.first) s.insert(t1);
            if (t2.first) s.insert(t2);
            if (t3.first) s.insert(t3);
        }
        else return false;
    }
    while (s.size()) {
        if (s.size() == 1) return false;
        auto t1 = *s.begin();
        s.erase(s.begin());
        auto t2 = *s.begin();
        s.erase(s.begin());
        ans2.pb(mp(t1.second, t2.second));
        t1.first++, t2.first++;
        if (t1.first) s.insert(t1);
        if (t2.first) s.insert(t2);
    }
    if (!s.size()) return true;
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    string s;
    fr(i, n)
        s += '0';
    int mx = *min_element(a, a + n);
    for (int i = mx; i >= 0; i--)
        if (solve(i, n)) {
            cout << i << endl;
            if (ans3.size())
                cout << 1 + (int)ans2.size() << endl;
            else
                cout << ans2.size() << endl;
            if (ans3.size()) {
                s[ans3[0]] = s[ans3[1]] = s[ans3[2]] = '1';
                cout << s << endl;
                s[ans3[0]] = s[ans3[1]] = s[ans3[2]] = '0';
            }
            for (auto t: ans2) {
                s[t.first] = s[t.second] = '1';
                cout << s << endl;
                s[t.first] = s[t.second] = '0';
            }
            return 0;
        }

    ans2.clear();
    cout << 0 << endl;
    fr(i, n)
        fr(j, a[i])
            if (i)
                ans2.pb(mp(0, i));
            else
                ans2.pb(mp(1, i));
    cout << ans2.size() << endl;
    for (auto t: ans2) {
        s[t.first] = s[t.second] = '1';
        cout << s << endl;
        s[t.first] = s[t.second] = '0';
    }
}