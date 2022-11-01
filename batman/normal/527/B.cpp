//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (500*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(ll x,ll y){ return a[x] > a[y]; }
 
string s,t;
ll a[26][26],p,n;
int Sa1378
{   
    IB
    cin>>n;
    cin>>s>>t;
    for(int i=0;i<s.size();i++)
        if(s[i]!=t[i])
        {
            p++;
            a[s[i]-'a'][t[i]-'a']=i+1;

        }
    if(p==1 || p==0)    
    {
        cout<<p<<endl<<-1<<" "<<-1<<endl;
        return 0;
    }   
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            if(a[i][j] && a[j][i])
            {
                cout<<p-2<<endl<<a[i][j]<<" "<<a[j][i]<<endl;
                return 0;
            }       
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            for(int k=0;k<26;k++)
                if(a[i][j] && a[j][k])
                {
                    cout<<p-1<<endl<<a[i][j]<<" "<<a[j][k]<<endl;
                    return 0;
                }
    cout<<p<<endl<<-1<<" "<<-1<<endl;               
    return 0;
}