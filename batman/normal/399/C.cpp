#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll a,b,res=-INF,res2;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b;
    if(a==0)
    {
        cout<<-b*b<<"\n";
        for(int i=0;i<b;i++)cout<<'x';
        return 0;
    }
    if(b==0)
    {
        cout<<a*a<<"\n";
        for(int i=0;i<a;i++)cout<<'o';
        return 0;
    }
    for(int i=1;i<=a;i++)
    {
        ll ans=(i-1)+(a-i+1)*(a-i+1);
        ll saghf=b-b/(i+1)*(i+1);
        ll kaf=i+1-saghf;
        ans-=kaf*(b/(i+1))*(b/(i+1));
        ans-=saghf*(b/(i+1)+1)*(b/(i+1)+1);
        if(ans>res)res=ans,res2=i;
    }
    cout<<res<<"\n";
    ll saghf=b-b/(res2+1)*(res2+1);
    ll kaf=res2+1-saghf;
    vector <ll> num,num2;
    for(int i=0;i<kaf;i++)num.push_back(b/(res2+1));
    for(int i=0;i<saghf;i++)num.push_back(b/(res2+1)+1);
    for(int i=0;i<res2-1;i++)num2.push_back(1);
    num2.push_back(a-res2+1);
    for(int i=0;i<res2;i++)
    {
        for(int j=0;j<num[i];j++)cout<<'x';
        for(int j=0;j<num2[i];j++)cout<<'o';
    }
    for(int j=0;j<num[res2];j++)cout<<'x';
    return 0;
}