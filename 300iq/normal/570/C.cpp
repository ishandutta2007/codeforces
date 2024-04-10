#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = (int) 3e5 + 7;

char c[MAXN];

string get() {
    scanf(" %s", &c);
    return string(c);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    string s = get();
    int i;
    char c;
    int cur = 0;
    forn (i, s.size()) {
        cur += (i + 1 < n && s[i] == s[i + 1] && s[i] == '.');
    }
    while (m--) {
        scanf("%d %c", &i, &c);
        i--;
        if (c == '.' && s[i] != '.') {
            cur += (i + 1 < n && s[i + 1] == '.');
            cur += (i - 1 >= 0 && s[i - 1] == '.');
            s[i] = c;
        } else if (c != '.' && s[i] == '.') {
            cur -= (i + 1 < n && s[i + 1] == '.');
            cur -= (i - 1 >= 0 && s[i - 1] == '.');
            s[i] = c;
        }
        printf("%d\n", cur);
    }
}