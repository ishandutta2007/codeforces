#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int lDiv[MAXN], phi[MAXN], gcdSum[MAXN],
    f[MAXN], fs[MAXN], f1s[MAXN], f2s[MAXN];
vector<int> pr;

int main() {
    ios_base::sync_with_stdio(false);
    lDiv[1] = 1;
    phi[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        int pi = i / lDiv[i];
        if(!(pi % lDiv[i]))
            phi[i] = phi[pi] * lDiv[i];
        else
            phi[i] = phi[pi] * (lDiv[i] - 1);
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            long long p = (long long)pr[j] * i;
            if(p >= MAXN)
                break;
            lDiv[p] = pr[j];
        }
    }
    for(int i = 1; i < MAXN; i++)
        for(int j = 1; j * j <= i; j++)
            if(!(i % j)) {
                gcdSum[i] = (gcdSum[i] + j * phi[i / j]) % MOD;
                if(j * j != i)
                    gcdSum[i] = (gcdSum[i] + (i / j) * phi[j]) % MOD;
            }
    for(int i = 1; i < MAXN; i++)
        f[i] = ((long long)i * (i + 1) * (2 * i + 1) / 3 -
                3ll * i * i + 2 * gcdSum[i]) % MOD;
    for(int i = 1; i < MAXN; i++) {
        fs[i] = (fs[i - 1] + f[i]) % MOD;
        f1s[i] = (f1s[i - 1] + (long long)i * f[i]) % MOD;
        f2s[i] = (f2s[i - 1] + (((long long)i * i) % MOD) * f[i]) % MOD;
    }
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++) {
        int n, m;
        cin >> n >> m;
        int l = min(n, m),
            ans = ((((long long)(n + 1) * (m + 1)) % MOD) * fs[l]) % MOD;
        ans = (ans + MOD - (((long long)(n + m + 2) * f1s[l]) % MOD)) % MOD;
        ans = (ans + f2s[l]) % MOD;
        cout << ans << '\n';
    }
    return 0;
}