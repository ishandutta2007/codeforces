#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

long long a[200], dp[200];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1] = a[1] - 1;
    for (int i = 2; i <= n; i++){
        dp[i] = (a[i] - 1) * i;
    }
    dp[n] += n;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans += dp[i];
    }
    cout << ans << endl;
}