#include <bits/stdc++.h>
#define pb push_back
#define fr(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = 1e4 + 10;
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 2e3 + 10;
const ld MAX = 1e18;
const int N = 1e6 + 10;

string t[N];

int main() {
    //freopen("a.in", "r", stdin);
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    t1 %= 12, t2 %= 12, h %= 12;
    bool a12 = false, a21 = false;
    vector <int> v12, v21;
    int c1 = t1 * 5;
    while (c1 != 5 * t2) {
        v12.pb(c1);
        c1 = (c1 + 1) % 60;
    }
    int c2 = t2 * 5;
    while (c2 != 5 * t1) {
        v21.pb(c2);
        c2 = (c2 + 1) % 60;
    }

    for (auto t: v12) {
        if (t == h * 5)
            a12 = true;
        if (t == m)
            a12 = true;
        if (t == s)
            a12 = true;
    }
    for (auto t: v21) {
        if (t == h * 5)
            a21 = true;
        if (t == m)
            a21 = true;
        if (t == s)
            a21 = true;
    }
    if (a12 && a21) {
        cout << "NO";
    }
    else
    cout << "YES";
}