using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


 int dp[50005][2][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int x;
         cin >> x;
         for(int i=0; i<n; i++){
             v[i] -=x;
         }
        for(int i=0; i<n+1; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        for(int i=0; i<n; i++){
            dp[i+1][0][0] = max(dp[i][0][0], dp[i][1][0]);
            dp[i+1][1][0] = max(dp[i][0][1], dp[i][1][1]);
            dp[i+1][0][1] = max(dp[i][0][0], dp[i][1][0]) + 1;
            dp[i+1][1][1] = 0;
            if(i > 0 && v[i] + v[i-1] >= 0){
                dp[i+1][1][1] = dp[i][0][1] + 1;
            }
            if(i > 1 && v[i] + v[i-1] >= 0 && v[i] + v[i-1] + v[i-2] >= 0){
                dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][1][1] + 1);
            }
        }
        cout << max(max(dp[n][0][0], dp[n][0][1]), max(dp[n][1][0], dp[n][1][1])) << endl;
    }

    
}