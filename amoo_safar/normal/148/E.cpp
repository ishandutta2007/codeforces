#include<iostream>
using namespace std;
typedef long long ll;

ll dp[3][10001];
ll ps1[101];
ll ps2[101];
ll a[100];
int main(){
    ll n,m,d,s,l;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> d;
        for(int j = 0;j<d;j++) cin >> a[j];
        ps1[0] = 0;
        for(int j =1;j<=d;j++) ps1[j] = ps1[j-1]+a[j-1];
        ps2[0] = 0;
        for(int j = 1;j<=d;j++) ps2[j] = ps2[j-1]+a[d-j];
        //cout << 2 << endl;
        for(int j = 0;j <= d;j++){
            for(int k = 0;k<=j;k++){
                l = j-k;
                dp[1][j]= max(dp[1][j],ps1[k]+ps2[l]);
            }
        }
        //cout << 2 << endl;
        for(int j = 0;j <= 10000;j++){
            for(int k =0;k<=d;k++){
                if(j+k > 10000) continue;
                dp[2][j+k] = max(dp[2][j+k],dp[0][j]+dp[1][k]);
            }
        }
        for(int j = 0;j<=10000;j++){
            dp[0][j] = max(dp[0][j],dp[2][j]);
            dp[2][j] = 0;
        }
        for(int j = 0;j<=d;j++) dp[1][j] = 0;
        //for(int j = 0;j<=3;j++) cout << dp[0][j] << " ";
        //cout << endl;
    }
    ll ma = dp[0][0];
    for(int i = 0;i <= m;i++)ma = max(ma,dp[0][i]);
    cout << ma << endl;
    return 0;
}
//2 3
//3 3 7 2
//3 4 2 5