//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.1 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (100*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MOD 1000000007
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll t,k,a,b,dp[N],sum[N];

int main()
{ 
    cin>>t>>k;
    dp[0]=1;
    for(int i=1;i<=100*1000;i++)
    {
        dp[i]=dp[i-1];
        if(i>=k)
            dp[i]+=dp[i-k];
        dp[i]%=MOD; 
        sum[i]=sum[i-1]+dp[i];
        sum[i]%=MOD;
    }
        
    for(int i=0;i<t;i++)
    {
        ll c;
        cin>>a>>b;
        c=sum[b]-sum[a-1];
        if(c<0)
            c+=MOD;
        cout<<c<<endl;    
    }   
    return 0;
}