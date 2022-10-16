#include <iostream>
#include <string>

using namespace std;

const int MAXN = 105, MOD = 1000 * 1000 * 1000 + 7;
int p2[2 * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    p2[0] = 1;
    for(int i = 1; i < 2 * MAXN; i++)
        p2[i] = (2 * p2[i - 1]) % MOD;
    string x;
    cin >> x;
    int n = x.length(), ans = 0;
    for(int i = 0; i < n; i++)
        if(x[n - i - 1] == '1')
            ans = (ans + (long long)p2[2 * i] * p2[n - i - 1]) % MOD;
    cout << ans << '\n';
    return 0;
}