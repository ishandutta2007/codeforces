#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
int prev_ans = 0;

inline int ask(int x) {
    if (x == 0) return prev_ans;
    cout << "+ " << x << endl;
    cin >> prev_ans;
    return prev_ans;
}

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    int l = 1, r = n, sum = 0;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int cnt = (n - m % n) % n;
        sum += cnt;
        int res = ask(cnt);
        l += cnt;
        r += cnt;
        m += cnt;
        if (l / n == res) r = m;
        else l = m;
    }
    cout << "! " << l << endl;
}

/*

 */