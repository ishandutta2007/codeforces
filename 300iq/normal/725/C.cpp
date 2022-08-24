#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
	string s, x, y;
    cin >> s;
    int l = 0, r = 0;
	for (int i = 0; i < (int) s.size(); i++) {
        for (int j = i + 1; j < (int) s.size(); j++) {
            if (s[i] == s[j]) {
                l = i, r = j;
            }
        }
    }
    if (r - l == 1) {
        cout << "Impossible\n";
    } else {
        int j = (r - l) / 2;
        for (int i = r - j - 1; i >= l; i--) x += s[i];
        for (int i = r - j; i < r; i++) y += s[i];
        int i = (l - 1 + 27) % 27;
        while ((int) x.size() < 13) x += s[i], i = (i + 27 - 1) % 27;
        i = (r + 1) % 27;
        while ((int) y.size() < 13) y += s[i], i = (i + 1) % 27;
        if ((int) x.size() > 13) x.erase(--x.end());
        if ((int) y.size() > 13) y.erase(--y.end());
        cout << x << '\n' << y << '\n';
    }
}