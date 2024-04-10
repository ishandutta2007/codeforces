#include <bits/stdc++.h>


using namespace std;

const int M = 1000100;
const int mod = 1000000007;

#define long long long

int n, k, m;
long l;
int a[M];
bool g[M];

long d[M], h[M], sum[M], ds[M];

void read() {
    cin >> n >> l >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void makeSum() {
    fill(ds, ds + m, 0);
    for (int i = 0; i < n; ++i)
        ds[a[i]] = (ds[a[i]] + d[i]) % mod;

    sum[0] = 0;
    for (int i = 1; i <= m; ++i)
        sum[i] = (sum[i - 1] + ds[i - 1]) % mod;
}

void upd(long &ans, long t) {
    ans = (ans + (((l / n) - t + 1) % mod) * sum[m]) % mod;
    for (int i = 0; i < l % n; ++i)
        ans = (ans + d[i]) % mod;
    //cerr << "u " << ans << endl;
}

void kill() {
    set<int> s;
    for (int i = 0; i < n; ++i) {
//        g[i] = s.count(a[i]) == 0;
        s.insert(a[i]);
    }

    vector<int> as(s.begin(), s.end());
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin();
    m = as.size();
    
    
    for (int i = 0; i < n && i < l; ++i)
        d[i] = 1;
    
    long ans = 0;
    makeSum();
    upd(ans, 1);
    for (int t = 1; t < k && 1ll * t * n < l; ++t) {
        for (int i = 0; i < n && 1ll * t * n + i < l; ++i)
            h[i] = sum[a[i] + 1];

        copy(h, h + n, d);
        fill(h, h + n, 0);
        makeSum();
        upd(ans, t + 1);
    }
    
    cout << ans << endl;     
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}