#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll tavan(ll a,ll n,ll mod){ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define MOD ((ll)1e9+7)

string s[N];
bool is[2][N];
ll ans1=MOD,ans2=MOD;

int main()
{
    for(int i=0;i<8;i++)cin>>s[i];
    for(ll i=0;i<8;i++)
        for(ll j=0;j<8;j++)
        {
            if(s[i][j]=='W')
            {
                is[0][j]=1;
                if(is[1][j]==0)
                    ans1=min(ans1,i);
            }
            if(s[i][j]=='B')
            {
                is[1][j]=1;
            }
        }
    for(int i=0;i<N;i++)is[0][i]=is[1][i]=0;    
    for(ll i=7;i>=0;i--)
        for(ll j=0;j<8;j++)
        {
            if(s[i][j]=='W')
            {
                is[0][j]=1;
            }
            if(s[i][j]=='B')
            {
                is[1][j]=1;
                if(is[0][j]==0)
                    ans2=min(ans2,7-i);
            }
        }   
    if(ans1<=ans2)cout<<"A";
    else cout<<"B";
    return 0;
}