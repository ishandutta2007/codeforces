#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e5 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const ll MOD = 1e9 + 7;

int s[10];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, n) {
        int t;
        cin >> t;
        s[t]++;
    }
    if (s[7] || s[5]) {
        cout << -1;
        return 0;
    }
    int c124 = 0, c126 = 0, c136 = 0;
    c124 = s[4];
    s[4] -= c124, s[1] -= c124, s[2] -= c124;
    if (s[1] < 0 || s[2] < 0) {
        cout << -1;
        return 0;
    }
    c126 = s[2];
    s[1] -= c126, s[2] -= c126, s[6] -= c126;
    if (s[1] < 0 || s[6] < 0) {
        cout << -1;
        return 0;
    }
    c136 = s[3];
    s[1] -= c136, s[3] -= c136, s[6] -= c136;
    if (s[1] < 0 || s[6] < 0 || c124 + c126 + c136 != n / 3) {
        cout << -1;
        return 0;
    }
    fr(i, c124)
        cout << "1 2 4" << endl;
    fr(i, c126)
        cout << "1 2 6" << endl;
    fr(i, c136)
        cout << "1 3 6" << endl;
}