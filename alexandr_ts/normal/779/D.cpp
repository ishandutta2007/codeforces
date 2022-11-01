#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

int a[N];
string s, t;

bool solve(int cnt) {
    string s1 = "";
    fr(i, s.size())
        s1 += '0';
    frab(i, cnt, s.size())
        s1[a[i] - 1] = s[a[i] - 1];
    int cur = 0;
    fr(i, s.size()) {
        if (cur < t.size() && s1[i] == t[cur])
            cur++;
    }
    return cur == t.size();
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> s >> t;
    fr(i, s.size())
        cin >> a[i];
    int l = -1, r = s.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (solve(m))
            l = m;
        else
            r = m;
    }
    cout << l;
}