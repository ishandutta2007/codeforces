#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 10000005;
const int MOD = 1000000007;

int minP[N], mu[N];
int a[500005], n, cnt[N];
int b[1000];
int pw2[500005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    for (int i = 2; i * i < N; i++) {
        if (minP[i] == 0) {
            for (int j = i * i; j < N; j += i) {
                if (minP[j] == 0) minP[j] = i;
            }
        }
    }
    pw2[0] = 1;
    for (int i = 1; i < 500005; i++) pw2[i] = (pw2[i - 1] + pw2[i - 1]) % MOD;
    for (int i = 2; i < N; i++) if (minP[i] == 0) minP[i] = i;
    mu[1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) mu[j] -= mu[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vector<int> p;
        int foo = a[i];
        while (foo != 1) {
            int prime = minP[foo];
            p.pb(prime);
            while (foo % prime == 0) foo /= prime;
        }
        b[1] = 1;
        int cur = 1;
        for (int i = 0; i < sz(p); i++) {
            for (int j = 1; j <= cur; j++) {
                b[cur + j] = b[j] * p[i];
                cnt[b[cur + j]]++;
            }
            cur = cur * 2;
        }
    }
    int nSet = 0;
    for (int i = 2; i < N; i++) {
        if (mu[i] == 0) continue;
        if (cnt[i] == 0) continue;
        nSet -= mu[i] * (pw2[cnt[i]] - 1);
        if (nSet < 0) nSet += MOD;
        nSet = nSet % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmpAns = 0;
        vector<int> p;
        int foo = a[i];
        while (foo != 1) {
            int prime = minP[foo];
            p.pb(prime);
            while (foo % prime == 0) foo /= prime;
        }
        b[1] = 1;
        int cur = 1;
        for (int i = 0; i < sz(p); i++) {
            for (int j = 1; j <= cur; j++) {
                b[cur + j] = b[j] * p[i];
                int u = b[cur + j];
                tmpAns -= mu[u] * (pw2[cnt[u]] - 1);
                if (tmpAns < 0) tmpAns += MOD;
                tmpAns = tmpAns % MOD;
            }
            cur = cur * 2;
        }
        ans += (nSet - tmpAns) % MOD;
        if (ans < 0) ans += MOD;
        ans %= MOD;
    }
    cout << ans;
    return 0;
}