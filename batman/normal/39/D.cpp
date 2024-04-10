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
    int a[3],ex;
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<3;i++)
    {
        cin>>ex;
        if(ex==a[i])
        {
            cout<<"YES";
            return 0;
        }
    }   
    cout<<"NO";
    return 0;
}