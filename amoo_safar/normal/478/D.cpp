#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;

ll dp[2][200001];

int main(){
    ll r,g;
    cin >> r >> g;
    if(r == 0 or g==0){
        cout << 1;
        return 0;
    }
    dp[0][1] = 1;
    dp[0][0] = 1;
    ll h = 1;
    ll s = r+g-1;
    while(s > h){
        h++;
        s -= h;
    }
    ll h2;
    for(int i = 1;i<h;i++){
        h2 = i+1;
        //cout << dp[0][4] << endl;
        //cout << h2 << endl;
        for(int j = 0;j <= r;j++) {
            dp[1][j] = dp[0][j];
            //cout << j << " "<< 1 <<endl;
        }
        for(int j = h2;j <= r;j++) {
            dp[1][j] += dp[0][j-h2];
            //cout << j << " "<< 2 << j << " "  << dp[0][j] <<" " << dp[0][j-h2]<<endl;
        }
        for(int j = 0;j<=r;j++)dp[0][j] = dp[1][j]%1000000007;
        //for(int j = 0;j<=r;j++)cout << dp[0][j] << " ";
        //cout << endl;
    }
    ll t = 0;
    for(int i = r;i >= max((ll)0,r-s);i--) t = (t + dp[0][i])%1000000007;
    cout << t;
    return 0;
}