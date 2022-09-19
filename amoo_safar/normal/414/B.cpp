#include<iostream>
using namespace std;
typedef long long ll;

ll dp[2001][2000];
ll ta[46];
int main(){
    for(int i = 0;i<2001;i++){
        dp[i][0] = 1;
    }
    ta[0] = 0;
    for(int i=1;i<46;i++){
        ta[i] = ta[i-1]+i+i-1;
    }
    //cout << 3;
    ll t,l;
    for(int i = 0;i < 2001;i++){
        for(int j = 1;j < 2000;j++){
            t = 0;
            l = 0;
            for(int k = 1;ta[k]<i;k++){
                //cout << 2;
                l = k;
                if(i%k == 0){
                    t += dp[k][j-1]+dp[i/k][j-1];
                    t %= 1000000007;
                }
            }
            if(ta[l+1] == i){
                t += dp[l+1][j-1];
                t %= 1000000007;
            }
            dp[i][j] = t;
            //cout << t << endl;
        }
        //cout << i << endl;
    }
    ll n,k;
    cin >> n >> k;
    ll o = 0;
    for(int i = 1;i<=n;i++){
        o += dp[i][k-1];
        o %= 1000000007;
    }
    cout << o;
    return 0;
}