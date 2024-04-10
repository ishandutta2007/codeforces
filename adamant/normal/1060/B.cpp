#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

int S(int x) {
    int s = 0;
    while(x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int my_b(int x) {
    if(x < 10) {
        return x;
    }
    int ans = 1;
    int all_9 = 1;
    while(x) {
        if(x < 10) {
            ans *= x + all_9;
            x = 0;
        } else {
            all_9 &= (x % 10) == 9;
            ans *= 10;
            x /= 10;
        }
    }
    return ans - 1;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int t = my_b(n);
    cout << S(t) + S(n - t) << endl;
}