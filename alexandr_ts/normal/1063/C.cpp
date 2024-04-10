#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll MAX = 1e9;
const ll MAX2 = 1e7;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;


int f(string s) {
    if (s == "black")
        return 1;
    return 0;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    /// left up
    cout << 1 << " " << MAX - 1 << endl;
    n--;
    string ans;
    cin >> ans;

    vector <int> resp;
    resp.pb(f(ans));

    int i = 0;
    while (f(ans) == resp[0] && n > 0) {
        cout << MAX - 1 << " " << MAX - 1 - i * MAX2 << endl;
        i++, n--;
        cin >> ans;
        resp.pb(f(ans));
    }

    if (!n) {
        if (resp.back() == resp[0]) {
            cout << "0 0 " << MAX - 1 << " 0" << endl;
        } else {
            cout << "1 " << MAX - MAX2 * (i - 1) - 10 << " " << MAX - 1 << " " << MAX - MAX2 * (i - 1) << endl;
        }
        return 0;
    }

    int l = 10, r = MAX - 10;
    while (n) {
        int m = (l + r) / 2;
        cout << m << " " << 1 << endl;
        cin >> ans;
        resp.pb(f(ans));
        if (f(ans) == resp[0]) {
            l = m;
        } else {
            r = m;
        }
        n--;
    }

    if (l + 1 == r) {
        cout << l << " " << 0 << " " << MAX - 10 << " " << MAX - 1 << endl;
        return 0;
    }
    cout << l + 1 << " " << 1 << " " << MAX - 1 << " " << MAX - MAX2 * (i - 1) << endl;
}