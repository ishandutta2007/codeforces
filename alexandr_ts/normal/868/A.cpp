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
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] == s) {
            cout << "YES";
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)

    if (t[i][1] == s[0] && t[j][0] == s[1]) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}