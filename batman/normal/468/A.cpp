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


int main()
{ 
    int n;
    cin>>n;
    
    if (n>=4)
        cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(;n>5;n-=2)
        cout<<n<<" - "<<n-1<<" = 1"<<endl<<"1 * 1 = 1"<<endl;
    if (n==5)   
        cout<<"5 - 3 = 2"<<endl<<"1 + 2 = 3"<<endl<<"3 * 4 = 12"<<endl<<"2 * 12 = 24"<<endl;
    else
        cout<<"1 * 2 = 2"<<endl<<"3 * 4 = 12"<<endl<<"2 * 12 = 24"<<endl;
    return 0;
}