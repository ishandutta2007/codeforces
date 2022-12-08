#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t --) {
        ll n;
        cin >> n;
        vector<ll> xs(n);
        ll sqr_sum = 0;
        ll asum = 0;
        for(int i = 0; i < n; i ++) {
            ll x;
            cin >> x;
            sqr_sum += x*x;
            asum += x;
            xs[i] = -x;
        }
        ll bsum = 0;
        for(int i = 0; i < n; i ++) {
            ll x;
            cin >> x;
            sqr_sum += x*x;
            bsum += x;
            xs[i] += x;
        }
        ll sum = asum + bsum;
        bitset<20000> dp;
        dp.set(asum);
        for(int d : xs) {
            if(d == 0) {continue;}
            if(d > 0) {
                for(int s = sum; s >= d; s --) {
                    if(dp[s-d]) {
                        dp.set(s);
                    }
                }
            } else {
                sum += d;
                for(int s = 0; s <= sum; s ++) {
                    if(dp[s-d]) {
                        dp.set(s);
                    }
                }
                sum -= d;
            }
        }

        ll found = 1e18;
        ll lowbest = (sum) / 2;
        ll upbest = (sum + 1) / 2;
        for(int i = 0;; i ++) {
            if(dp[lowbest - i]) {
                found = lowbest - i;
                break;
            }
            if(dp[upbest + i]) {
                found = upbest + i;
                break;
            }
            
        }
        ll res = (n-2) * sqr_sum + found * found + (sum-found) * (sum-found);
        cout << res << "\n";
    }

    return 0;
}