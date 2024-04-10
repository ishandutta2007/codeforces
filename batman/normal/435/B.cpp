//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
string s;
int n,k;
int Sa1378
{ 
    cin>>s>>k;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        char maxim=0;
        int index=-1;
        for(int j=i+1;j<min(i+k+1,n);j++)
            if(maxim<s[j])
                maxim=s[j],index=j;
        if(index!=-1 && s[index]>s[i])
        {
            for(int j=index;j>i;j--)
                swap(s[j],s[j-1]);
            k-=(index-i);       
        }   
    }
    cout<<s;
    return 0;
}