#include <bits/stdc++.h>

using namespace std;

struct trio{
    int t, d, p, id;
    bool operator < (trio t) const{
        return d < t.d;
    }
};

int dp[101][4005];
trio arr[105];
int par[101][4005];
int N;
stack<int> stk;

int main(){
    cin >> N;
    for(int i =1; i<=N; i++){
        cin >> arr[i].t >> arr[i].d >> arr[i].p;
        arr[i].id = i;
    }
    sort(arr+1, arr+1+N);
    int ans = 0;
    for(int i =1; i<=N; i++){
        for(int j = arr[i].d-arr[i].t-1; j>=0; j--){
            dp[i][j+arr[i].t] = max(dp[i-1][j+arr[i].t], dp[i-1][j] + arr[i].p);
            if(dp[i-1][j] + arr[i].p == dp[i][j+arr[i].t]){
                par[i][j+arr[i].t] = arr[i].id;
            }
            else{
                par[i][j+arr[i].t] = par[i-1][j+arr[i].t];
            }
        }
        for(int j = arr[i].t-1; j>=0; j--){
            dp[i][j] = dp[i-1][j];
            par[i][j] = par[i-1][j];
        }
    }
    for(int i =1; i<=arr[N].d-1; i++){
        ans = dp[N][ans] > dp[N][i] ? ans : i;
    }
    cout << dp[N][ans] << endl;
    int crntwt = ans, crnti = N;
    while(par[crnti][crntwt]){
        stk.push(par[crnti][crntwt]);
        for(int i = 1; i<=N; i++){
            if(arr[i].id == par[crnti][crntwt]){
                crnti = i-1;
                crntwt -= arr[i].t;
                break;
            }
        }
    }
    cout << stk.size() << endl;
    while(stk.size()){
        cout << stk.top() << " ";
        stk.pop();
    }
}