// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
string s;
bool dp[N][2];
bool check(ll i, ll l){
    bool eq=1;
    for(ll j = 0;j<l;j++){
        eq=eq&&s[i+j]==s[i+l+j];
    }
    return !eq;
}
set<string> rs;
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> s;
    ll n = s.length();
    dp[n-2][0]=1;
    dp[n-3][1]=1;
    for(ll i=n-4;i>4;i--){
        for(ll l = 2;l<4;l++){
            for(ll l2=2;l2<4;l2++){
                if(i+l+l2>n) continue;
                if(l!=l2) dp[i][l-2]|=dp[i+l][l2-2];
                else if(check(i, l)) dp[i][l-2]|=dp[i+l][l2-2];
            }
        }
    }
    for(ll i=5;i+1<n;i++){
        string ss="";
        ss+=s[i];
        ss+=s[i+1];
        if(i+2==n||(dp[i+2][0]&&check(i, 2))||dp[i+2][1]) rs.insert(ss);
        if(i+2==n) continue;
        ss+=s[i+2];
        if(i+3==n||(dp[i+3][1]&&check(i, 3))||dp[i+3][0]) rs.insert(ss);
    }
    cout<<rs.size()<<'\n';
    for(auto i : rs){
        cout<<i<<'\n';
    }
}