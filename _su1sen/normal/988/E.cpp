#include<bits/stdc++.h>

using namespace std;

constexpr int INF = 1000000000;

int main() {
    long long n;
    cin >> n;
    if (n % 25 == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> cnt(10, 0);
    vector<int> digits;
    while (n) {
        int r = (int) (n % 10);
        digits.push_back(r);
        ++cnt[r];
        n /= 10;
    }
    int d = digits.size();
    int ans = INF;
    // 00
    if (cnt[0] >= 2) {
        int l = -1, r = -1;
        for (int i = 0; i < d; ++i) {
            if (digits[i] == 0) {
                if (l < 0) l = i;
                else if (r < 0) r = i;
            }
        }
        ans = min(ans, l + r - 1);
    }
    // 25
    if (cnt[2] >= 1 and cnt[5] >= 1) {
        int p5 = -1, p2 = -1, k = -1;
        for (int i = 0; i < d; ++i) {
            if (digits[i] == 5) {
                if (p5 < 0) p5 = i;
                else k = i;
            } else if (digits[i] == 2) {
                if (p2 < 0) p2 = i;
                else k = i;
            } else if (digits[i] != 0) {
                k = i;
            }
        }
        int t = INF;
        if (p5 == d - 1 and digits[d - 2] == 0) {
            if (k >= 0) {
                t = d - 1 - k;
                p5 -= 1;
                p2 -= k < p2;
            }
        } else if (p2 == d - 1 and digits[d - 2] == 0) {
            if (k >= 0) {
                t = d - 1 - k;
                p2 -= 1;
                p5 -= k < p5;
            }
        } else t = 0;
        t += p2 + p5 - (p2 > p5);
        ans = min(ans, t);
    }
    // 50
    if (cnt[0] >= 1 and cnt[5] >= 1) {
        vector<int> ds = digits;
        int p0 = -1, p5 = -1, k = -1;
        for (int i = 0; i < d; ++i) {
            if (ds[i] == 5) {
                if (p5 < 0) p5 = i;
                else k = i;
            } else if (ds[i] == 0) {
                if (p0 < 0) p0 = i;
            } else {
                k = i;
            }
        }
        int add = 0;
        for (int i = p0; i > 0; --i) {
            int tmp = ds[i]; ds[i] = ds[i - 1]; ds[i - 1] = tmp;
            ++add;
        }
        if (p5 < p0) ++p5;
        if (k >= 0 and k < p0) ++k;
        int t = INF;
        if (p5 == d - 1 and digits[d - 2] == 0) {
            if (k >= 0) {
                t = d - 1 - k;
                p5 -= 1;
            }
        } else t = 0;
        t += p5 - 1;
        ans = min(ans, t + add);
    }
    // 75
    if (cnt[7] >= 1 and cnt[5] >= 1) {
        int p5 = -1, p7 = -1, k = -1;
        for (int i = 0; i < d; ++i) {
            if (digits[i] == 5) {
                if (p5 < 0) p5 = i;
                else k = i;
            } else if (digits[i] == 7) {
                if (p7 < 0) p7 = i;
                else k = i;
            } else if (digits[i] != 0) {
                k = i;
            }
        }
        int t = INF;
        if (p5 == d - 1 and digits[d - 2] == 0) {
            if (k >= 0) {
                t = d - 1 - k;
                p5 -= 1;
                p7 -= k < p7;
            }
        } else if (p7 == d - 1 and digits[d - 2] == 0) {
            if (k >= 0) {
                t = d - 1 - k;
                p7 -= 1;
                p5 -= k < p5;
            }
        } else t = 0;
        t += p7 + p5 - (p7 > p5);
        ans = min(ans, t);
    }
    if (ans >= INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}