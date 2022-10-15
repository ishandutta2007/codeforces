//============================================================================
// Author      : arsijo
// made in Ukraine
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    bool bo[100000];
    int ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        bo[ar[i]-1] = false;
    }
    int dp[n];
    dp[n-1] = 1;
    bo[ar[n-1]-1] = true;
    for (int i = n - 2; i >= 0; i--){
         if (!bo[ar[i]-1]){
             dp[i] = dp[i+1] + 1;
         }else{
             dp[i] = dp[i+1];
         }
         bo[ar[i]-1] = true;
     }
     int a;
     for (int i = 0; i < m; i++){
          cin >> a;
          cout << dp[a-1] << endl;
     }
}