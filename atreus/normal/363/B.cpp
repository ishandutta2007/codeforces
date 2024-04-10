#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 2e5 + 500;
long long sum[maxn], dp[maxn], a[maxn];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum[i] = a[i];
        if (i != 0)
            sum[i] += sum[i - 1];
    }
    for (int i = k - 1; i < n; i++){
        if (i != k - 1)
            dp[i] = sum[i] - sum[i - k];
        else
            dp[i] = sum[i];
    }
    long long ans = 1000000000, inx = 0;
    for (int i = k - 1; i < n; i++){
        if (ans > dp[i]){
            ans = dp[i];
            inx = i;
        }
    }
    cout << inx - k + 2 << endl;
}