#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1e5 + 1000;
int a[maxn], dp[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]] ++;
    }
    for (int i = 1; i <= maxn; i++)
        if (b[i] > 0)
            dp[1] ++;
    for (int i = 2; i <= n; i++){
        b[a[i - 1]] --;
        if (b[a[i - 1]] == 0)
            dp[i] = dp[i - 1] - 1;
        else
            dp[i] = dp[i - 1];
    }
    for (int i = 0; i < m; i++){
        int l;
        cin >> l;
        cout << dp[l] << endl;
    }
}