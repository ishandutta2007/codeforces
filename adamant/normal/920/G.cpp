#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42;

int mu[maxn];
vector<int> primes;
int lp[maxn];
vector<int> divs[maxn];


int count(int p, int m) {
    int ans = 0;
    for(auto it: divs[p]) {
        ans += mu[it] * (m / it);
    }
    return ans;
}

void solve() {
    int x, p, k;
    cin >> x >> p >> k;
    int l = x, r = 1e9;
    int init = count(p, x);
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(count(p, m) - init < k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l + 1 << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    mu[1] = 1;
    for(int i = 2; i < maxn; i++) {
        if(!lp[i]) {
            lp[i] = i;
            mu[i] = -1;
            primes.push_back(i);
        }
        for(auto it: primes) {
            int t = it * i;
            if(it > lp[i] || t >= maxn) {
                break;
            }
            lp[it * i] = it;
            mu[it * i] = mu[i] * (i % it ? -1 : 0);
            
        }
    }
    for(int i = 1; i < maxn; i++) {
        if(mu[i] != 0) {
            for(int j = i; j < maxn; j += i) {
                divs[j].push_back(i);
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}