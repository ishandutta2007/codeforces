#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 2e3 + 500;
int a[maxn], dp[maxn];
bool mark[maxn];

int dfs(int x){
    if (mark[x])
        return dp[x];
    if (a[x] == -1){
        dp[x] = 1;
        mark[x] = true;
        return dp[x];
    }
    mark[x] = true;
    dp[x] = dfs(a[x]) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        if (!mark[i])
            dfs(i);
    }
    int k = 0;
    for (int i = 1; i <= n; i++)
        k = max(k, dp[i]);
    cout << k << endl;
}