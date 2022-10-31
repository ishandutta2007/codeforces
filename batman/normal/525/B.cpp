//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio(0);
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }


string s;
int m;
int mark[200*1000];
int Sa1378
{ 
    cin>>s>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        mark[a-1]++;
    }
    for(int i=1;i<s.size();i++)
        mark[i]=mark[i-1]+mark[i];      
    for(int i=0;i<s.size();i++)
    {
        int j=i;
        if(j>s.size()/2)
            j=s.size()-j-1;
        if(mark[j]%2)
            cout<<s[s.size()-i-1];
        else
            cout<<s[i]; 
    }
    return 0;
}