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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int wn = n, wm = m;
    string ans = "";
    for (int i = 0; i < n + m; i++) {
        if (wn > 0) {
            ans += "B", wn--;
        }
        if (wm > 0) {
            ans += "G", wm--;
        }
    }
    int cnt = 0;
    for (int i = 0; i < (int) ans.size() - 1; i++) {
        if (ans[i] != ans[i + 1]) {
            cnt++;
        }
    }
    wn = n, wm = m;
    string tans = "";
    for (int i = 0; i < n + m; i++) {
        if (wm > 0) {
            tans += "G", wm--;
        }
        if (wn > 0) {
            tans += "B", wn--;
        }
    }
    int pnt = 0;
    for (int i = 0; i < (int) ans.size() - 1; i++) {
        if (tans[i] != tans[i + 1]) {
            pnt++;
        }
    }
    if (cnt > pnt) {
        puts(ans.c_str());
    } else {
        puts(tans.c_str());
    }
}