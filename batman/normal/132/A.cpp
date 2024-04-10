//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (101*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] < a[y]; }
string s,nows;
int last,now;
int Sa1378
{ 
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        last=now;
        now=0;
        int ex=s[i]-0;
        while(ex)
        {
            nows+=(ex%2+'0');
            ex/=2;
        }
        while(nows.size()<8)
            nows+='0';
        //chie(nows);
        for(int j=nows.size()-1,x=1;j>=0;j--,x*=2)
                now+=x*(nows[j]-'0');
        int ans=last-now;
        if(ans<0)
            ans+=256;       
        cout<<ans%256<<endl;        
        nows="";
    }
    return 0;
}