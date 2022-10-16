#include <bits/stdc++.h>
using namespace std;
static int dp[105][5];
int gym(int x){
    if(x == 2 || x == 3){
        return 1;
    }
    return 0;
}
int contest(int x){
    return x%2;
}
int main(){
    vector<int> a;
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int d;
        scanf("%d", &d);
        a.emplace_back(d);
    }
    if(a[0] == 1 || a[0] == 2){
        dp[0][a[0]] = 1;
    }
    if(a[0] == 3){
        dp[0][1] = 1;
        dp[0][3] = 1;
        dp[0][2]=  1;
    }
    for(int i = 1; i<n; i++){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1], max(dp[i-1][2], dp[i-1][3])));
        if (a[i] == 1){
            dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + 1;
        }
        else if(a[i] == 2){
            dp[i][2] = max(dp[i-1][0],dp[i-1][1]) +1;
        }
        else if(a[i] == 3){
            dp[i][3] = dp[i-1][0]+1;
            dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + 1;
            dp[i][2] = max(dp[i-1][0],dp[i-1][1]) +1;
        }


    }
    cout << n - max(max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]), dp[n-1][3]);
    return 0;
}