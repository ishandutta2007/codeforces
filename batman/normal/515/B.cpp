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
#define MOD (ll)1e9+7
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,a,ex;
bool na[110],nb[110];
int main()
{ 
    cin>>n>>m>>a;
    for(int i=0;i<a;i++)
        cin>>ex,na[ex]=true;
    cin>>a;     
    for(int i=0;i<a;i++)
        cin>>ex,nb[ex]=true;
    for(int i=0;i<1000*1000;i++)
    {
        if(na[i%n]==true)
            nb[i%m]=true;
        if(nb[i%m]==true)
            na[i%n]=true;   
    }           
    for(int i=0;i<n;i++)
        if(na[i]==false)
        {
            cout<<"No"<<endl;
            return 0;
        }
    for(int i=0;i<m;i++)
        if(nb[i]==false)
        {
            cout<<"No"<<endl;
            return 0;
        }
    cout<<"Yes"<<endl;      
    return 0;
}