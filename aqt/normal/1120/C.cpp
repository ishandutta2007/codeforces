#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int dp[5005];
string s;
int lps[5005];
int rht[5005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> A >> B;
    cin >> s;
    int lst = 0;
    for(int i = 1; i<=N; i++){
        dp[i] = dp[i-1] + A;
        fill(lps+1, lps+1+N, i);
        for(int j = i, k = i+1; k<=N; ){
            if(s[j-1] == s[k-1]){
                lps[k++] = ++j;
            }
            else if(j == i){
                k++;
            }
            else{
                j = lps[j-1];
            }
        }
        for(int j = i, k=1; k<i && j <= N; ){
            if(s[j-1] == s[k-1]){
                rht[i] = max(rht[i], j);
                j++, k++;
            }
            else if(j == i){
                k++;
            }
            else{
                j = lps[j-1];
            }
        }
        for(int j = 1; j<=i; j++){
            if(rht[j] >= i){
                if(rht[j] < rht[j-1]){
                    cout << rht[j] << " " << (j) << " " << rht[j-1] <<endl;
                    return 0;
                }
                dp[i] = min(dp[i], dp[j-1] + B);
            }
        }
    }
    cout << dp[N] << endl;
}