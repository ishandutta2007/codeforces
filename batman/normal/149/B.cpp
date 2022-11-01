#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

string s,a,b;
vector <ll> ans;

bool check(ll x)
{
    ll p=0,q=0;
    for(ll i=(ll)a.size()-1,num=1;i>=0;i--,num*=x)
    {
        if('0'<=a[i] && a[i]<='9')p+=(ll)(a[i]-'0')*num;
        else p+=(ll)(a[i]-'A'+10)*num;  
    }
        
    for(ll i=(ll)b.size()-1,num=1;i>=0;i--,num*=x)
    {
        if('0'<=b[i] && b[i]<='9')q+=(ll)(b[i]-'0')*num;
        else q+=(ll)(b[i]-'A'+10)*num;
    }
    if(p<24 && q<60)return 1;
    return 0;       
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    ll i,maxi=1;
    for(i=0;s[i]!=':';i++)
    {
        a+=s[i];
        if('0'<=s[i] && s[i]<='9')maxi=max(maxi,(ll)(s[i]-'0')+1);
        else maxi=max(maxi,(ll)(s[i]-'A')+11);  
    }
    i++;
    for(;i<s.size();i++)
    {
        b+=s[i];
        if('0'<=s[i] && s[i]<='9')maxi=max(maxi,(ll)(s[i]-'0')+1);
        else maxi=max(maxi,(ll)(s[i]-'A')+11);  
    }
    ll p=0;
    for(i=maxi;i<200;i++)
    {
        if(check(i))
            p++,ans.push_back(i);
    }
    if(!p)cout<<0;
    else if(ans.size()>100)cout<<-1;
    else
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
    return 0;
}