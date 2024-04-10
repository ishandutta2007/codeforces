////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 100*1001
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");


int n,m;
int main()
{
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<m;j++)
                cout<<"#";
        }
        else if(i%4==1)
        {
            for(int j=0;j<m-1;j++)
                cout<<".";
            cout<<"#";  
        }
        else
        {
            cout<<"#";
            for(int j=0;j<m-1;j++)
                cout<<".";
        }
        cout<<endl; 
                
    }
        
    return 0;
}