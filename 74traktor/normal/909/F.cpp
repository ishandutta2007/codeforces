#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int ans[maxn], used[maxn];

inline int oks(vector < int > a) {
    for (int i = 0; i < (int)a.size(); ++i) if (a[i] == i + 1 || (a[i]&(i + 1)) == 0) return 0;
    return 1;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt = 1, N;
    cin >> n;
    N = n;
    if (n % 2 == 1) {
        cout << "NO" << '\n';
    }
    else {
        cout << "YES" << '\n';
        while (n > 0) {
            int x = 1;
            while (x * 2 <= n) x *= 2;
            for (int w = x; w <= n; ++w) {
                ans[w] = x - (w - x) - 1;
                ans[x - (w - x) - 1] = w;
            }
            n -= 2 * (n - x + 1);
        }
        for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
        cout << '\n';
    }
    n = N;
    if (n <= 5) {
        cout << "NO" << '\n';
        exit(0);
    }
    while (n > 0) {
        int x = 1;
        while (x * 2 <= n) x *= 2;
        if (x == n) {
            cout << "NO" << '\n';
            exit(0);
        }
        if (n == 6) {
            ans[1] = 3, ans[2] = 6, ans[3] = 2, ans[4] = 5, ans[5] = 1, ans[6] = 4;
            n = 0;
            break;
        }
        if ((n - x + 1) % 2 == 1) {
            int R = n, cur = (n - x) / 2 + 1;
            for (int i = x; cur > 0; ++i, cur--) {
                if (i == x + 1) continue;
                ans[i] = R;
                ans[R] = i;
                R--;
            }
            ans[x + 1] = x - 1;
            ans[x - 1] = x + 1;
            n = x - 2;
        }
        else {
            while (n > 7) {
                ans[n] = n - 1;
                ans[n - 1] = n;
                n -= 2;
            }
            ans[1] = 3, ans[2] = 6, ans[3] = 1, ans[4] = 5, ans[5] = 4, ans[6] = 7, ans[7] = 2;
            n = 0;
        }
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << '\n';
    /*for (int i = 1; i <= N; ++i) {
        if ((ans[i] == i) || (ans[i]&i) == 0) cout << i << '\n';
    }*/
    /*n = N;
    vector < int > a;
    for (int i = 1; i <= n; ++i) cnt *= i, a.push_back(i);
    while (cnt--) {
        if (oks(a)) {
            for (auto key : a) cout << key << " ";
            exit(0);
        }
        if (cnt > 0) next_permutation(a.begin(), a.end());
    }*/
    return 0;
}