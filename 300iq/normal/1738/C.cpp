#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

mt19937 rnd(228);

const int inf = 1e9;

typedef long long ll;

bool used[102][102][2][2][2];
bool ans[102][102][2][2][2];

bool win(int l, int r, int alice, int bob, int turn) {
    if (l == 0 && r == 0) {
        return alice == 0;
    } else {
        if (used[l][r][alice][bob][turn]) return ans[l][r][alice][bob][turn];
        used[l][r][alice][bob][turn] = true;
        bool as = false;
        if (turn == 0) {
            if (l && win(l - 1, r, alice, bob, turn ^ 1)) {
                as = true;
            }
            if (r && win(l, r - 1, alice ^ 1, bob, turn ^ 1)) {
                as = true;
            }
        } else {
            as = true;
            if (l && !win(l - 1, r, alice, bob, turn ^ 1)) {
                as = false;
            }
            if (r && !win(l, r - 1, alice, bob ^ 1, turn ^ 1)) {
                as = false;
            }
        }
        return ans[l][r][alice][bob][turn] = as;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto f = [&] (int val, int cnt) {
        return (val + cnt - 1) / cnt;
    };
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) l++;
            else r++;
        }
        bool ret = win(l, r, 0, 0, 0);
        if (ret) cout << "Alice\n";
        else cout << "Bob\n";
    }
}