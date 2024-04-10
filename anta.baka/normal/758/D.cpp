#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;

int n;
string s;
int len;
long long dp[60];

long long toint(int l, int r) {
    long long ret = 0;
    for(int i = l; i <= r; i++)
        ret = ret * 10 + s[i] - '0';
    return ret;
}

int main() {
    cin >> n >> s;
    len = s.size();
    dp[0] = s[0] - '0';
    for(int i = 1; i < len; i++) {
        dp[i] = (s[i] != '0' ? inf : dp[i - 1] * n);
        for(int j = i; j >= 0; j--) {
            if(i - j + 1 > 19)
                break;
            if(i - j + 1 == 19) {
                if(s[j] != '1')
                    break;
                bool flag = false;
                for(int k = j + 1; k <= i; k++)
                    if(s[k] != '0') {
                        flag = true;
                        break;
                    }
                if(flag)
                    break;
            }
            if(s[j] == '0')
                continue;
            long long x = toint(j, i);
            if(x >= n)
                break;
            if(dp[j - 1] > inf / n)
                continue;
            dp[i] = min(dp[i], (j > 0 ? dp[j - 1] * n : 0) + x);
        }
    }
    cout << dp[len - 1];
}