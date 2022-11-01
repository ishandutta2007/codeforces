#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int64_t> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    srand(time(0));
    random_shuffle(A.begin(), A.end());
    int64_t ans = 1;
    int lim = n <= 100 ? n: 11;
    for (int i = 0; i < lim && i < n; ++i) {
        int64_t x = A[i];
        vector<int64_t> pdivs, allDivs;
        for (int64_t i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                }
                pdivs.push_back(i);
            }
        } //
        if (x > 1) {
            pdivs.push_back(x);
        }
        x = A[i];
        for (int64_t i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                allDivs.push_back(i);
            }
        }
        int pos = allDivs.size();
        for (int64_t i = 1; i * i < x; ++i) {
            if (x % i == 0) {
                allDivs.push_back(x / i);
            }
        }
        int64_t cNumber = A[i];
        reverse(allDivs.begin() + pos, allDivs.end());
        vector<int> count(SZ(allDivs), 0);
        for (int i = 0; i < n; ++i) {
            int64_t g = __gcd(A[i], cNumber);
            count[lower_bound(allDivs.begin(), allDivs.end(), g) - allDivs.begin()]++;
        }
        for (int64_t d: pdivs) {
            for (int i = SZ(count) - 1; i >= 0; --i) {
                if (allDivs[i] % d == 0) {
                    int p = lower_bound(allDivs.begin(), allDivs.end(),
                            allDivs[i] / d) - allDivs.begin();
                    count[p] += count[i];
                }
            }
        }
        
        for (int i = 0; i < SZ(count); ++i) {
            if (count[i] >= (n + 1) / 2) {
                ans = max(ans, allDivs[i]);
            }
        }
    }
    cout << ans << '\n';
}