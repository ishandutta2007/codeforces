#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

int main() {
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    int n, s;
    cin >> n >> s;
    vector <int> a(n);
    vector <int> cnt(n);
    vector <int> suf(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s--;
    int res = 0;
    if (a[s] != 0) {
        a[s] = 0;
        res++;
    }
    if (n == 1) {
        cout << res << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i != s) {
            cnt[a[i]]++;
        }
    }
    suf[n - 1] = (cnt[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + (cnt[i]);
    }
    int lol = 0;
    int ans = n - 1 + res;
    for (int i = 1; i < n; i++) {
        lol += (cnt[i] == 0);
        int change = suf[i + 1] + cnt[0];
        ans = min(ans, res + max(lol, change));
    }
    cout << ans << '\n';
}