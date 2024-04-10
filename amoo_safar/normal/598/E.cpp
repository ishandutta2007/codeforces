#include<iostream>

typedef long long ll;
using namespace std;

ll dp[31][31][51];
int main(){
    dp[1][1][0] = 0;
    dp[1][1][1] = 0;
    ll m,mini,br;
    for(ll i = 1;i < 31;i++){
        for(ll j = 1;j < 31;j++){
            if( i == j and j == 1) continue;
            for(ll k = 0;k <= min((ll)50,i*j);k++){
                if( k == 0){
                    dp[i][j][k] = 0;
                    continue;
                }
                if(i*j == k){
                    dp[i][j][k] = 0;continue;
                }
                mini = 10000000;
                for(ll i2 = 1;i2 < i;i2++){
                    br = j*j;
                    m = i2*j;
                    for(ll k2 = min(k,m);k2 > 0;k2--){
                        if(k - k2 > (i-i2)*j ) continue;
                        mini = min(mini,br + dp[i2][j][k2]+ dp[i-i2][j][k-k2]);
                    }
                }
                for(ll j2 = 1;j2 < j;j2++){
                    br = i*i;
                    m = j2*i;
                    for(ll k2 = min(k,m);k2 > 0;k2--){
                        if(k - k2 > (j-j2)*i ) continue;
                        mini = min(mini,br + dp[i][j2][k2]+ dp[i][j-j2][k-k2]);
                        //cout << br + dp[i][j2][k2]+ dp[i][j-j2][k-k2]<< endl;
                    }
                }
                dp[i][j][k] = mini;
                //cout << mini << br << endl;
            }
        }
        //cout << i << endl;
    }
    //cout << 2 << endl;
    ll n,a,b,c;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a >> b >> c;
        cout << dp[a][b][c] << endl;
    }
    return 0;
}