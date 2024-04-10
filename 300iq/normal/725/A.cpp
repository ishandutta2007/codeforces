#include <bits/stdc++.h>

#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define bit(x) __builtin_popcount(x)
#define pb push_back
#define popb pop_back
#define ll long long

using namespace std;

const int N = (int) 2e5 + 7;
int u[N];
bool good[N];


int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (u[i]) {
            ans += good[i];
        } else {
            int cur = i;
            vector <int> pos;
            pos.pb(cur);
            bool ged = 0;
            while (!u[cur]) {
                u[cur] = 1;
                cur = (cur + (s[cur] == '>') - (s[cur] == '<'));
                if (cur < 0 || cur >= n) {
                    ged = 1;
                    break;
                }
                pos.pb(cur);
            }
            if (ged) {
                for (auto c : pos) {
                    good[c] = 1;
                }
                ans++;
            } else {
                if (good[cur]) {
                    for (auto c : pos) {
                        good[c] = 1;
                    }
                    ans++;
                } 
            }
        }
    }
    cout << ans << endl;
}