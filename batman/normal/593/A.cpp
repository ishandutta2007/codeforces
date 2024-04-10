#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define MOD ((ll)1e9+7)

ll n;
ll a[110][30],mark[110],one[110];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll num=0;
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(a[i][s[j]-'a']==0)num++;
            a[i][s[j]-'a']++;
            if(num==3)
            {
                mark[i]=1;
                break;
            }
        }
        if(num==1)
            one[i]=1;
    }
    ll res=0;
    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
        {
            ll ans=0;
            for(int p=0;p<n;p++)
                if(!mark[p])
                {
                    if(one[p] && (a[p][i] || a[p][j]))ans+=a[p][i]+a[p][j];
                    else if(!one[p] && a[p][i] && a[p][j])ans+=a[p][i]+a[p][j]; 
                }   
            res=max(ans,res);   
        }   
    cout<<res;  
    return 0;
}