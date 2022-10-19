#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long w, l;
    scanf("%lld %lld", &w, &l);
    long long s = w + w + l + l - 4;
    vector<long long> ans = {1, 2};
    for (long long i = 3; i * i <= s; ++i) {
        if (s % i == 0) {
            if ((w - 1) % i == 0 && (l - 1) % i == 0) {
                ans.push_back(i);
            }
            else if (w % i == 0 && (l - 2) % i == 0) {
                ans.push_back(i);
            }
            else if ((w - 2) % i == 0 && l % i == 0) {
                ans.push_back(i);
            }
            if (s / i != i) {
                if ((w - 1) % (s / i) == 0 && (l - 1) % (s / i) == 0) {
                    ans.push_back(s / i);
                }
                else if (w % (s / i) == 0 && (l - 2) % (s / i) == 0) {
                    ans.push_back(s / i);
                }
                else if ((w - 2) % (s / i) == 0 && l % (s / i) == 0) {
                    ans.push_back(s / i);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d", (int)ans.size());
    for (auto it : ans) {
        printf(" %lld", it);
    }
    printf("\n");
}

int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}