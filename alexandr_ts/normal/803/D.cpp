#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int N = 2e5 + 10;

string s;

vector <int> ls;

bool ok(int h, int w) {
    int cnt = 0, cur = 0;
    fr(i, ls.size()) {
        if (ls[i] > w) return false;
        if (cur + ls[i] > w) {
            cnt++;
            cur = ls[i];
        }
        else {
            cur += ls[i];
        }
    }
    if (cur)
        cnt++;
    return cnt <= h;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();
    getline(cin, s);

    int cur = 0;
    fr(i, s.size()) {
        if (s[i] == '-' || s[i] == ' ') {
            ls.pb(cur + 1);
            cur = 0;
        }
        else
            cur++;
    }
    if (cur)
        ls.pb(cur);

    int l = 0, r = s.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ok(n, m))
            r = m;
        else
            l = m;
    }
    cout << r;
}