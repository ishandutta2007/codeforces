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
ifstream fin("input.txt");
ofstream fout("output.txt");

bool mark[110];
int main()
{ 
    int n,a,b;
    cin>>n>>a;
    for(int i=0;i<a;i++)
    {
        int ex;
        cin>>ex;
        mark[ex]=true;
        
    }
    cin>>b;
    for(int i=0;i<b;i++)
    {
        int ex;
        cin>>ex;
        mark[ex]=true;
        
    }
    for(int i=1;i<=n;i++)
        if(mark[i]==false)
        {
            cout<<"Oh, my keyboard!";
            return 0;
        }
    cout<<"I become the guy.";  
        
    
    
    return 0;
}