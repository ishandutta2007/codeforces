#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

const int N = 5e5 + 11;
const int M = 5e2 + 11;

char ch[15];
string s;

int d[M][M];

void solve() {
    int n;
    scanf("%d", &n);
    fr(i, n) {
        scanf("%s", &ch);
        s = ch;
        assert(isalpha(s.back()));
        assert(s.size() > 0);

        if (s[0] != s.back()) {
            fr(j, 26) {
                if (d[j][s[0] - 'a'])
                    d[j][s.back() -  'a'] = max((int)d[j][s.back() - 'a'], 
                        (int)d[j][s[0] - 'a'] + (int)s.size());
                else if (j == s[0] - 'a') {
                    d[j][s.back() - 'a'] = max(d[j][s.back() - 'a'], (int)s.size());
                }
            }
        } else {
            fr(j, 26)
                if (d[j][s[0] - 'a'] || j == s[0] - 'a')
                    d[j][s[0] - 'a'] += s.size();
        }

    }

    int ans = 0;
    fr(i, 26)
        ans = max(ans, d[i][i]);
    cout << ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    solve();
}