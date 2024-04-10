#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = 100000000000000;
const int Y = 100;
const int m = 997;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<long long>ans;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long res = INF;
        string s;
        cin >> s;
        int ct = 0;
        vector<int>a(k, 0);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ++ct;
                ++a[i % k];
            }
        }
        for (int os = 0; os < k; ++os) {
            int tr = ct - a[os];
            vector<int>dp1(1, 0);
            vector<int>dp3(1, 0);
            vector<int>dp2(1, 0);
            for (int i = os; i < n; i += k) {
                int j = dp1.size();
                dp1.push_back(0);
                dp3.push_back(0);
                dp2.push_back(0);
                if (s[i] == '1') {
                    dp1[j] = min(dp1[j - 1], dp2[j - 1]);
                    dp2[j] = dp2[j - 1] + 1;
                    dp3[j] = min(dp3[j - 1], dp1[j - 1]) + 1;
                }
                else {
                    dp1[j] = min(dp1[j - 1], dp2[j - 1]) + 1;
                    dp2[j] = dp2[j - 1];
                    dp3[j] = min(dp3[j - 1], dp1[j - 1]);
                }
                if (i + k >= n) {
                    dp1.back() = min(dp1.back(), dp2.back());
                    dp1.back() = min(dp1.back(), dp3.back());
                    tr += dp1.back();
                }
            }

            res = min(res, (long long)tr);
        }
        ans.push_back(res);
    }
    for (auto x : ans)cout << x << endl;
    return 0;
}
//