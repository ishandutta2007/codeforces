#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll a[1001];
ll MOD = 1000000007;
ll dp[1001][1001];
int main(){
    dp[0][0] = 1;
    for(int i =0;i<1001;i++){
        for(int j = 0;j<=i;j++){
            if((j == 0) or(j==i)) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%MOD;
        }
    }
    /*for(int i =0;i<10;i++){
        for(int j =0;j<10;j++)cout << dp[i][j] << " ";
        cout << endl;
    }*/

    a[1] = 0;
    ll t;
    ll j;
    ll m = -1;
    for(int i = 2;i<=1000;i++){
        t = 0;
        j = i;
        while(j>0){
            if(j%2==1)t++;
            j/=2;
        }
        a[i] = a[t]+1;
        m = max(m,a[i]);
    }
    ll kk;
    string n;
    cin >> n;
    cin >> kk;
    ll out = 0;
    if(kk > 5){
        cout << 0;
        return 0;
    }
    if(kk == 0){
        cout << 1;
        return 0;
    }
    if(n == "1"){
        if(kk == 0)cout << 1;
        else cout << 0;
        return 0;
    }
    if(kk == 1){
        cout << n.size()-1;
        return 0;
    }
    ll oc = 0;
    for(int i = 0;i<n.size();i++){
        if(n[i] == '1')oc++;
    }
    ll occ;
    for(int k = 1;k<1001;k++){
        if(a[k] == kk-1){
            occ = k;
            if(oc == occ)out ++;
            //cout << k << " " << out << endl;
            for(int i =0;i<n.size();i++){
                if(n[i] == '1'){
                    if(n.size()-i-1 >= occ and occ >=0){
                        //cout <<  n.size()-i-1<< " " <<occ <<endl;
                        out = (out + dp[n.size()-i-1][occ])%MOD;
                    }
                    occ--;
                }
            }
        }
    }
    cout << out%MOD;
    return 0;
}