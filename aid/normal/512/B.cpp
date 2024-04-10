#include <iostream>
#include <map>

using namespace std;

const int MAXN = 305;
int l[MAXN], c[MAXN];
map<int, int> dp[2];

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        int pi = (i & 1), ni = ((i + 1) & 1);
        dp[ni].clear();
        for(map<int, int>::iterator it = dp[pi].begin(); it != dp[pi].end(); it++) {
            if(dp[ni].find(it->first) == dp[ni].end() || dp[ni][it->first] > it->second)
                dp[ni][it->first] = it->second;
            int val = gcd(it->first, l[i]);
            if(dp[ni].find(val) == dp[ni].end() || dp[ni][val] > it->second + c[i])
                dp[ni][val] = it->second + c[i];
        }
    }
    if(dp[n & 1].find(1) == dp[n & 1].end())
        cout << -1 << '\n';
    else
        cout << dp[n & 1][1] << '\n';
    return 0;
}