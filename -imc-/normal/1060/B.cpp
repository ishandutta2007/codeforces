#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

//#define int li
//const int mod = 1000000007;

vector<int> getDigits(li n) {
    vector<int> d;
    while (n) {
        d.push_back(n % 10);
        n /= 10;
    }
    reverse(all(d));
    return d;
}

void solve(__attribute__((unused)) bool read) {
    li num;
    cin >> num;

    vector<int> digits = getDigits(num);

    int n = digits.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    dp[0][0] = 0;
    //dp[0][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int carry = 0; carry < 2; ++carry) {
            if (dp[i][carry] == -1) {
                continue;
            }

            //cout << "dp " << i << " " << carry << " is " << dp[i][carry] << endl;

            for (int a = 0; a < 10; ++a) {
                for (int b = 0; b < 10; ++b) {
                    for (int ext_carry = 0; ext_carry < 2; ++ext_carry) {
                        if ((a + b + ext_carry >= 10) != carry) {
                            continue;
                        }

                        if ((a + b + ext_carry) % 10 != digits[i]) {
                            continue;
                        }

                        //cout << "go " << a << " " << b << " " << ext_carry << endl;
                        dp[i + 1][ext_carry] = max(dp[i + 1][ext_carry], dp[i][carry] + a + b);
                    }
                }
            }
        }
    }

    cout << dp[n][0] << "\n";
}