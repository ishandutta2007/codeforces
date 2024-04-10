#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> lft[5005], rht[5005];
vector<int> vec;
int dp[5005];
int t[5005];

int main(){
    cin >> N;
    int n;
    cin >> n;
    vec.push_back(n);
    for(int i = 2; i<=N; i++){
        cin >> n;
        if(vec.back() != n){
            vec.push_back(n);
        }
    }
    N = vec.size();
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=i; j++){
            t[j] = dp[j];
        }
        for(int j = i-1; j>0; j--){
            t[j] = max(t[j], t[j+1]);
            if(vec[i-1] == vec[j-1]){
                t[j] = max(t[j], dp[j+1]+1);
            }
        }
        for(int j= 1; j<=i; j++){
            dp[j] = t[j];
        }
    }
    cout << N-dp[1]-1 << endl;
}