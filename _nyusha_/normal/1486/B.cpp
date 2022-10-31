#include<bits/stdc++.h>

using namespace std;

#define int long long

int solve(vector < int > a) {
    int sum = 0;
    if ((int)a.size() % 2 == 1) return 1;
    for (int i = 0; i < (int)a.size();) {
        int j = i;
        while (j < (int)a.size() && a[i] == a[j]) ++j;
        int to = sum + (j - i);
        if (to == (int)a.size() / 2) {
            return a[j] - a[i] + 1;
        }
        else if (to > (int)a.size() / 2) return 1;
        sum = to;
        i = j;
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        vector < int > a,b;
        for (int i = 1; i <= n; ++i) {
            cin >> x >> y;
            a.push_back(x);
            b.push_back(y);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << solve(a) * solve(b) << '\n';
    }
    return 0;
}