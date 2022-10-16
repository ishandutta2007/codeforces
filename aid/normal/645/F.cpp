#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5, MAXX = 1000 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int a[MAXN], b[MAXN], cnt[MAXX], lDiv[MAXX], phi[MAXX], inv[MAXN], c[MAXN];
vector<int> pr;

void update(int pos, int &ans) {
    ans = (ans - (long long)phi[pos] * c[cnt[pos]]) % MOD;
    cnt[pos]++;
    ans = (ans + (long long)phi[pos] * c[cnt[pos]]) % MOD;
    if(ans < 0)
        ans += MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i < MAXX; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            int p = pr[j] * i;
            if(p >= MAXX)
                break;
            lDiv[p] = pr[j];
        }
    }
    phi[1] = 1;
    for(int i = 2; i < MAXX; i++) {
        int x = i, y = lDiv[i], p = 1;
        while(!(x % y)) {
            x /= y;
            p *= y;
        }
        phi[i] = phi[x] * (p - p / y);
    }
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < q; i++)
        cin >> b[i];
    inv[1] = 1;
    for(int i = 2; i <= n + q; i++)
        inv[i] = (MOD - (long long)(MOD / i) * inv[MOD % i] % MOD) % MOD;
    c[k] = 1;
    for(int i = k + 1; i <= n + q; i++)
        c[i] = (long long)c[i - 1] * i % MOD * inv[i - k] % MOD;
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;
    for(int i = 1; i < MAXX; i++)
        for(int j = 2 * i; j < MAXX; j += i)
            cnt[i] += cnt[j];
    int ans = 0;
    for(int i = 1; i < MAXX; i++)
        ans = (ans + (long long)phi[i] * c[cnt[i]]) % MOD;
    for(int i = 0; i < q; i++) {
        for(int j = 1; j * j <= b[i]; j++)
            if(!(b[i] % j)) {
                update(j, ans);
                if(j * j != b[i])
                    update(b[i] / j, ans);
            }
        cout << ans << '\n';
    }
    return 0;
}