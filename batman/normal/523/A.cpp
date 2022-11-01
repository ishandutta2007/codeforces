//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (110)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
string s[N];
ll w,h;
int Sa1378
{ 
    cin>>w>>h;
    for(int i=0;i<h;i++)
        cin>>s[i];
    for(int i=0;i<w;i++)
        for(int k=0;k<2;k++)
        {
            for(int j=0;j<h;j++)
                cout<<s[j][i]<<s[j][i];
            cout<<endl; 
        }
    return 0;
}