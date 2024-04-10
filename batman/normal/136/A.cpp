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

ifstream fin("input.txt");
ofstream fout("output.txt");

int n,a[110];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            if(a[j]==i)
            {
                cout<<j+1<<" ";
                break;
            }
                
    
    
    return 0;
}