#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (770)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

string s;
stack <ll> st;
ll match[N],dpl[N][N],dpr[N][N],dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')st.push(i);
        else match[st.top()]=i,match[i]=st.top(),st.pop();
    }
    for(int i=0;i<s.size();i++)dpr[i][i]=dpl[i][i]=2,dp[i][i]=3;
    for(ll t=2;t<=s.size();t++)
        for(ll i=0;i+t-1<s.size();i++)
        {
            ll j=i+t-1;
            if(s[i]==')' || (s[i]=='(' && match[i]>j))
                dpl[i][j]=(dpl[i+1][j]+dp[i+1][j])%MOD,dp[i][j]=(2*dpl[i+1][j]+dp[i+1][j])%MOD;
            else
            {
                ll p=match[i];
                dpl[i][j]=(((i+1<=p-1)?dpl[i+1][p-1]:1ll)*((p+1<=j)?dp[p+1][j]:1ll))%MOD;
                dpl[i][j]+=(2*((i+1<=p-1)?dpr[i+1][p-1]:1ll)*((p+1<=j)?dpl[p+1][j]:1ll))%MOD,dpl[i][j]%=MOD;
                dp[i][j]=dpl[i][j]+(((i+1<=p-1)?dpl[i+1][p-1]:1ll)*((p+1<=j)?dp[p+1][j]:1ll))%MOD,dp[i][j]%=MOD;
            }
            if(s[j]=='(' || (s[j]==')' && match[j]<i))
                dpr[i][j]=(dpr[i][j-1]+dp[i][j-1])%MOD;
            else
            {
                ll p=match[j];
                dpr[i][j]=(((p+1<=j-1)?dpr[p+1][j-1]:1ll)*((i<=p-1)?dp[i][p-1]:1ll))%MOD;
                dpr[i][j]+=(2*((p+1<=j-1)?dpl[p+1][j-1]:1ll)*((i<=p-1)?dpr[i][p-1]:1ll))%MOD,dpr[i][j]%=MOD;    
            }       
        }   
    cout<<dp[0][(ll)s.size()-1];
    return 0;
}