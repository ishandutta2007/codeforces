#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <random>
#endif

using namespace std;

typedef long long ll;
typedef long double ldb;

map<int, int> memo;

int ask(int x) {
    if (memo.count(x))
        return memo[x];
    cout << "? " << x << endl;
    int y;
    cin >> y;
    return memo[x] = y;
}

int main() {
    int n;
    cin >> n;
    if (n < 4) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cout << "? " << i + 1 << endl;
            cin >> arr[i];
        }
        cout << "! " << min_element(arr.begin(), arr.end()) - arr.begin() + 1 << endl;
    } else {
        int l1 = ask(1);
        int l2 = ask(2);
        if (l1 < l2) {
            cout << "! 1" << endl;
            return 0;
        }
        int r1 = ask(n - 1);
        int r2 = ask(n);
        if (r1 > r2) {
            cout << "! " << n << endl;
            return 0;
        }
        int l = 2;
        int r = n - 1;
        while (r - l > 4) {
            int m1 = (l + r) / 2;
            int m2 = m1 + 1;
            if (ask(m1) < ask(m2)) {
                r = m1;
            } else {
                l = m2;
            }
        }
        for (int i = l; i <= r; i++) {
            if (ask(i - 1) > ask(i) && ask(i) < ask(i + 1)) {
                cout << "! " << i << endl;
                return 0;
            }
        }
    }
}