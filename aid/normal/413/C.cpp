#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int a[MAXN], b[MAXN];
long long dp[MAXN][MAXN];
char auc[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        k--;
        b[i] = a[k];
        auc[k] = true;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
        if(!auc[i])
            ans += a[i];
    sort(b, b + m);
    int sum = 0;
    for(int i = 0; i < m; i++)
        sum += b[i];
    long long ans0 = ans + sum;
    for(int i = 0; i < m; i++) {
        sum -= b[i];
        long long ans1 = ans + sum;
        for(int j = 0; j <= i; j++)
            if(ans1 >= b[j])
                ans1 += ans1;
        ans0 = max(ans0, ans1);
    }
    cout << ans0 << '\n';
    return 0;
}