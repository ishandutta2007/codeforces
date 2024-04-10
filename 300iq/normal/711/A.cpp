#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 1000 + 7;

int main() {
    int n;
    cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool gg = 0;
    for (int i = 0; i < n; i++) {
        if (s[i][0] == s[i][1] && s[i][0] == 'O') {
            s[i][0] = '+';
            s[i][1] = '+';
            gg = 1;
            break;
        }
        if (s[i][3] == s[i][4] && s[i][3] == 'O') {
            s[i][3] = '+';
            s[i][4] = '+';
            gg = 1;
            break;
        }
    }
    if (!gg) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            puts(s[i].c_str());
        }
    }
}