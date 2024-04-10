#include <bits/stdc++.h>

using namespace std;

int N, K;
long long dp[200005][10];

void solve(int n, vector<int> t){
    int s = t.size();
    sort(t.begin(), t.end(), greater<int>());
    long long doub = 0, sum = 0;
    for(int i = 0; i<s; i++){
        sum += t[i];
        doub += t[i];
    }
    if(!t.empty()){
        doub += t[0];
    }
    for(int i = 0; i<10; i++){
        if(dp[n-1][i] == LLONG_MIN){
            continue;
        }
        dp[n][(i+s)%10] = max(dp[n][(i+s)%10], dp[n-1][i] + (i+s>9 ? doub : sum));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i<=N; i++){
        for(int m = 0; m<10; m++){
            dp[i][m] = LLONG_MIN;
        }
    }
    dp[0][0] = 0;
    for(int i =1 ; i<=N; i++){
        int best2 = 0, best3 = 0;
        vector<int> best1;
        int K;
        cin >> K;
        for(int m = 0; m<10; m++){
            dp[i][m] = dp[i-1][m];
        }
        for(int k = 1; k<=K; k++){
            int cst, dmg;
            cin >> cst >> dmg;
            if(cst == 1){
                best1.push_back(dmg);
            }
            else if(cst == 2){
                best2 = max(best2, dmg);
            }
            else{
                best3 = max(best3, dmg);
            }
        }
        sort(best1.begin(), best1.end(), greater<int>());
        vector<int> t;
        for(int j = 0; j<min((int)best1.size(), 3); j++){
            t.push_back(best1[j]);
            solve(i, t);
        }
        t.clear();
        if(best2){
            t.push_back(best2);
            solve(i, t);
            if(best1.size()){
                t.push_back(best1[0]);
                solve(i, t);
            }
            t.clear();
        }
        if(best3){
            t.push_back(best3);
            solve(i, t);
        }
    }
    long long ans = 0;
    for(int m = 0; m<10; m++){
        ans = max(dp[N][m], ans);
    }
    cout << ans << endl;
}