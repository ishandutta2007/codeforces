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

const int MAXN = (int) 1e5 + 7;
char c[MAXN];

string get() {
    scanf(" %s", c);
    return string(c);
}

int main() {
    string s = get();
    int ans = 1;
    int it = s.size();
    while (1) {
        string sub = "";
        if (it == 0) break;
        it--;
        while (it > 0 && s[it] == '0') {
            sub += '0';
            it--;
        }
        sub += s[it];
        reverse(all(sub));
        int t = sub.size();
        if (t < it) {
            ans++;
            continue;
        } else if (t == it) {
            bool b = 1;
            for (int j = 0; j <= it; j++) {
                if (s[j] != sub[j]) {
                    b = (s[j] > sub[j]);
                    break;
                }
            }
            if (b) {
                ans++;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    printf("%d\n", ans);
}