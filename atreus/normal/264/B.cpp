#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn], dp[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 0; i < n; i++){
        int def = 1;
        for (int j = 2; j <= sqrt(a[i]); j++){
            if (a[i] % j == 0){
                dp[a[i]] = max(dp[a[i]], dp[j] + 1);
                dp[a[i]] = max(dp[a[i]], dp[a[i] / j] + 1);
            }
        }
        for (int j = 2; j <= sqrt(a[i]); j++){
            if (a[i] % j == 0){
                dp[j] = max(dp[j], dp[a[i]]);
                dp[a[i] / j] = max(dp[a[i] / j], dp[a[i]]);
            }
        }
    //            for (int k = 0; k < n; k++)
      //      cout << dp[a[k]] << " ";
       // cout << endl;
    }
    int k = 0;
    for (int i = 0; i < n; i++){
        k = max(k, dp[a[i]]);
    }
    cout << k << endl;
}