#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=3005;
const ll p=998244353;
int dp[N][N];
int main(){
    string s, t;
    cin>>s>>t;
    //s.resize(4, 'a');
    //t="a";
    s='#'+s;
    t='#'+t;
    for(int j=0; j<=t.size(); j++){
        dp[0][j]=1;
    }
    for(int i=1; i<s.size(); i++){
        //cout<<i<<"\n";
        for(int j=1; j<t.size(); j++){
            if(t[j]==s[i]){
                dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=p;
            }
        }

        //cout<<"a";
        for(int j=0; j<((int)t.size()-i+1); j++){
            //cout<<i<<" "<<j<<" "<<t.size()<<" "<<(t.size()-i+1)<<"\n";
            if(t[j+i-1]==s[i]){
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=p;
            }
        }

        //cout<<"a";
        //cout<<i<<" "<<t.size()<<"\n";
        for(int j=max(1, ((int)t.size())-i+1); j<t.size(); j++){
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=p;
        }
        //cout<<dp[3][1];
        //cout<<"a";
        dp[i][t.size()]=(2*dp[i-1][t.size()])%p;
    }
    //cout<<"b";
    /*for(int i=0; i<s.size(); i++){
        for(int j=0; j<=t.size(); j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    ll ans=0;
    for(int i=t.size()-1; i<s.size(); i++){
        ans+=dp[i][1];
        ans%=p;
    }
    cout<<ans;
}