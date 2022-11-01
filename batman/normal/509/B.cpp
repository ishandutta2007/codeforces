////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 110
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}

ifstream fin("input.txt");
ofstream fout("output.txt");
int n,k,a[N],minim=1000,maxim;
int main()
{
    
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        minim=min(a[i],minim);
        maxim=max(a[i],maxim);
    }
    if(maxim-minim>k)
    {
        cout<<"NO"<<endl;
        return 0;
    }
            
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            cout<<j%k+1<<" ";
        }
        cout<<endl;
    }
        
        
    return 0;
}