#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], dp[MAXN], lDiv[MAXN], c[MAXN];
vector<int> pr;

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 2; i < MAXN; i++) {
        if(!lDiv[i]) {
            lDiv[i] = i;
            pr.push_back(i);
        }
        for(size_t j = 0; j < pr.size() && pr[j] <= lDiv[i]; j++) {
            long long p = (long long)pr[j] * i;
            if(p >= MAXN)
                break;
            lDiv[p] = pr[j];
        }
    }
    for(int i = 0; i < MAXN; i++)
        c[i] = -1;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        int k = a[i];
        while(k > 1) {
            int p = lDiv[k];
            for(int j = a[i] - p; j >= 0; j -= p)
                if(c[j] != -1) {
                    dp[i] = max(dp[i], dp[c[j]] + 1);
                    break;
                }
            while(lDiv[k] == p)
                k /= lDiv[k];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}