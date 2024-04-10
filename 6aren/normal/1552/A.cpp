#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin >> n >> s;
        int res = 0;
        string t = s;
        sort(t.begin(), t.end());
        for (int i = 0; i < n; i++) if (s[i] != t[i]) res++;
        cout << res << '\n';
    }

    return 0;
}