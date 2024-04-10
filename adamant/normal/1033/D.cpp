#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxn = 2e6 + 42;
const int mod = 998244353;
vector<int> primes;
map<int, int> lar;
int pr[maxn];
int sma[maxn];


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i < maxn; i++) {
        if(!pr[i]) {
            for(int j = i; j < maxn; j += i) {
                pr[j] = 1;
            }
            primes.push_back(i);
        }
    }
    int n;
    cin >> n;
    int a[n];
    int b[n];
    vector<int> pq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        bool found = false;
        for(auto it: primes) {
            while(a[i] % it == 0) {
                found = true;
                a[i] /= it;
                sma[it]++;
            }
        }
        if(!found) {
            int t = llround(sqrt(a[i]));
            bool sq = false;
            for(int j = max((int)2, t - 10); j < t + 10; j++) {
                if(j * j == a[i]) {
                    sq = true;
                    lar[j] += 2;
                }
            }
            if(!sq) {
                pq.push_back(a[i]);
            }
        } else if(a[i] != 1) {
            lar[a[i]]++;
        }
    }
    map<int, int> pqs;
    int ans = 1;
    for(auto it: pq) {
        bool split = false;
        for(auto jt: b) {
            int t = __gcd(it, jt);
            if(it != jt && t != 1) {
                int p = t, q = it / p;
                lar[p]++;
                lar[q]++;
                split = true;
                break;
            }
        }
        if(!split) {
            pqs[it]++;
        }
    }
    for(int i = 2; i < maxn; i++) {
        if(sma[i]) {
            ans *= (1 + sma[i]);
            ans %= mod;
        }
    }
    for(auto it: lar) {
        ans *= it.second + 1;
        ans %= mod;
    }
    for(auto it: pqs) {
        ans *= (it.second + 1) * (it.second + 1) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}