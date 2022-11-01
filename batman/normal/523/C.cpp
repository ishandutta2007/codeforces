//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (2200)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
string s,t;
ll p,i,j;
int Sa1378
{ 
    cin>>s>>t;
    for(i=0;i<t.size();i++)
    {
        if(s[p]==t[i])
        {
            p++;
            if(p==s.size())
                break;
        }
            
    }
    p--;
    for(j=t.size()-1;j>=0;j--)
    {
        if(s[p]==t[j])
        {
            p--;
            if(p==-1)
                break;
        }
    }
    if(i>=j)
        cout<<0;
    else
        cout<<j-i;  
            
    return 0;
}