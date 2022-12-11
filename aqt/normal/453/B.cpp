#include <bits/stdc++.h>

using namespace std;

int N, n;
vector<int> mask[1<<16];
int fact[60];
int dp[1<<16][101];
int lst[1<<16][101];
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int main(){
    cin >> N;
    for(int i = 1; i<=59; i++){
        for(int p =0; p<prime.size(); p++){
            if(i%prime[p] == 0){
                fact[i] |= (1<<p);
            }
        }
    }
    for(int i = 0; i<1<<16; i++){
        for(int j= 1; j<=59; j++){
            if((i&fact[j]) == fact[j]){
                mask[i].push_back(j);
            }
        }
    }
    for(int i= 1; i<=N; i++){
        cin >> n;
        for(int m = 0; m<1<<16; m++){
            dp[m][i] = INT_MAX;
            for(int k : mask[m]){
                if(dp[m][i] > dp[m^fact[k]][i-1] + abs(n-k)){
                    dp[m][i] = dp[m^fact[k]][i-1] + abs(n-k);
                    lst[m][i] = k;
                }
            }
        }
    }
    int crnt = (1<<16)-1;
    stack<int> stk;
    for(int i = N; i>0; i--){
        stk.push(lst[crnt][i]);
        crnt ^= fact[lst[crnt][i]];
    }
    while(stk.size()){
        cout << stk.top() << " ";
        stk.pop();
    }
}