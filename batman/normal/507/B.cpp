////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.0 //////////////////
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

ll r,a[2],b[2];
int main()
{
    cin>>r>>a[0]>>a[1]>>b[0]>>b[1];
    double ex=sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
    cout<<ceil(ex/(2*r));
    return 0;
}