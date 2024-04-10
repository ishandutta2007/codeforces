#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e2 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

void check1(string s) {
    string t = "AHIMOTUVWXY";
    fr(i, s.size())
        if (t.find(s[i]) == -1) {
            cout << "NO";
            exit(0);
        }
}

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    check1(s);
    fr(i, s.size())
        if (s[i] != s[(int)s.size() - i - 1]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";
}