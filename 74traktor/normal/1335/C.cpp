#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
map < int, int > cnt;

int oks(int x, int n, int y) {
    for (auto key : cnt) {
        if (key.second > x && y >= x) return 1;
        if (key.second == x && y - 1 >= x) return 1;
    }
    return 0;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int lef = 0, righ = n + 1;
        cnt.clear();
        set < int > Q;
        for (int i = 1; i <= n; ++i) Q.insert(a[i]), cnt[a[i]]++;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (oks(mid, n, (int)Q.size())) lef = mid;
            else righ = mid;
        }
        cout << lef << '\n';
    }
    return 0;
}