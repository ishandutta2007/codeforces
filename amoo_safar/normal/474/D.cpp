#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll dp[100001];
ll ps[100001];
int main(){
    ll t,k;
    cin >> t >> k;
    dp[0] = 1;
    for(int i = 1;i<k;i++)dp[i] = dp[i-1];
    for(int i = k;i<=100000;i++){
        dp[i] = (dp[i-1]+dp[i-k])% MOD;
    }
    ps[0] = 1;
    for(int i =1;i<=100000;i++){
        ps[i] = (ps[i-1]+dp[i])% MOD;
    }
    ll a,b,s;
    for(int i = 0;i<t;i++){
        cin >> a >> b;
        s = ps[b]-ps[a-1];
        if(s<0){
            s+=MOD;
        }
        cout << s << endl;
    }
    return 0;
}