#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector < int > a, b, c;
    int n, x, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x > 0) a.push_back(x);
        else if (x == 0) b.push_back(x);
        else c.push_back(x);
    }
    if ((int)b.size() == n) {
        cout << n << '\n';
        return 0;
    }
    if ((int)c.size() == 0) {
        int sum = 0;
        for (auto key : a) sum += key;
        cout << sum - (int)a.size() + (int)b.size() << '\n';
    }
    else if ((int)a.size() == 0) {
        if ((int)c.size() % 2 == 0) {
            int sum = 0;
            for (auto key : c) sum -= key;
            cout << sum - (int)c.size() + (int)b.size() << '\n';
        }
        else {
            int sum = 0;
            for (auto key : c) sum -= key;
            if ((int)b.size() != 0) {
                cout << sum - (int)c.size() + (int)b.size() << '\n';
            }
            else {
                sort(c.begin(), c.end());
                sum += c.back();
                cout << sum - ((int)c.size() - 1) - c.back() + 1 << '\n';
            }
        }
    }
    else {
        if ((int)c.size() % 2 == 0) {
            int sum1 = 0, sum2 = 0;
            for (auto key : a) sum1 += key;
            for (auto key : c) sum2 -= key;
            cout << sum1 - (int)a.size() + sum2 - (int)c.size() + (int)b.size() << '\n';
        }
        else {
            if ((int)b.size() != 0) {
                int sum1 = 0, sum2 = 0;
                for (auto key : a) sum1 += key;
                for (auto key : c) sum2 -= key;
                cout << sum1 - (int)a.size() + sum2 - (int)c.size() + (int)b.size() << '\n';
            }
            else {
                sort(c.begin(), c.end());
                sort(a.begin(), a.end());
                int sum1 = 0, sum2 = 0;
                for (auto key : a) sum1 += key;
                for (auto key : c) sum2 -= key;
                cout << min((sum1 - a[0] - ((int)a.size() - 1) + a[0] + 1 + sum2 - (int)c.size()), (sum2 + c.back() - ((int)c.size() - 1) + sum1 - (int)a.size() - c.back() + 1)) << '\n';
            }
        }
    }
    return 0;
}