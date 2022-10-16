#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 300 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int a[MAXN], lDiv[MAXN], inv[MAXN], c[MAXN], csum[MAXN];
vector<int> pr, b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i < MAXN; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            int p = pr[j] * i;
            if(p >= MAXN)
                break;
            lDiv[p] = pr[j];
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int x = a[i];
        while(x > 1) {
            int y = lDiv[x], p = 0;
            while(!(x % y)) {
                x /= y;
                p++;
            }
            b[y].push_back(p);
        }
    }
    inv[1] = 1;
    for(int i = 2; i <= n; i++)
        inv[i] = (MOD - (long long)(MOD / i) * inv[MOD % i] % MOD) % MOD;
    c[0] = 1;
    for(int i = 1; i < n; i++)
        c[i] = (long long)c[i - 1] * (n - i) % MOD * inv[i] % MOD;
    csum[0] = 0;
    for(int i = 0; i < n; i++)
        csum[i + 1] = (csum[i] + c[i]) % MOD;
    int ans = 0;
    for(int i = 2; i < MAXN; i++)
        if(lDiv[i] == i && !b[i].empty()) {
            sort(b[i].begin(), b[i].end());
            int pos = n - (int)b[i].size();
            for(size_t j = 0; j < b[i].size(); j++, pos++)
                ans = (ans + (long long)csum[pos] * b[i][j]) % MOD;
            pos = 0;
            for(int j = (int)b[i].size() - 1; j >= 0; j--, pos++)
                ans = (ans - (long long)csum[pos] * b[i][j]) % MOD;
        }
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}