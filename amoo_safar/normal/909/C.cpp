#include<iostream>
using namespace std;
unsigned long long int dp[2][5003];
int main(){
    int n;
    cin >> n;
    char a,l;
    cin >> a;
    l = a;
    dp[0][0] = 1;
    for(int i =1 ;i<n;i++){
        cin >> a;
        if(l == 'f'){
            if(a=='f'){
                for(int j =0;j<=i;j++){
                    dp[1][j+1] = dp[0][j];
                }
            } else {
                for(int j =0;j < 5003;j++){
                    dp[1][j+1] =dp[0][j];
                }
            }
        } else {
            if(a == 'f'){
                for(int j = i+2;j>=0;j--) {
                    dp[1][j] = dp[0][j]+dp[1][j+1];
                    dp[1][j] %= 1000000007;
                }
            } else {
                for(int j = i+2;j>=0;j--) {
                    dp[1][j] = dp[0][j]+dp[1][j+1];
                    dp[1][j] %= 1000000007;
                }
            }
        }
        l = a;
        for(int j =0;j<5003;j++){
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    unsigned long long sum = 0;
    for(int i =0;i<5003;i++){
        sum = sum + (unsigned long long) dp[0][i];
        sum = sum%1000000007;
    }
    cout << sum;
    return 0;
}