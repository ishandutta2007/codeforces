////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("milk3.in");
ofstream fout("milk3.out");
    
int main()
{ 
    int n,m;
    cin>>n>>m;
    if(m==0)
        cout<<n<<" "<<n;
    else if(n==0 && m==0)
        cout<<0<<" "<<0;
    else if(n==0 && m>0)
    {
        cout<<"Impossible";
        return 0;
    }
    else cout<<max(n,m)<<" "<<n+m-1;

    return 0;
}