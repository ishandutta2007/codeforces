////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 1100
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("milk3.in");
ofstream fout("milk3.out");



int main()
{ 
    
    int x0,y0,n,x[1010],y[1010];
    cin>>n>>x0>>y0;
    vector <double> v;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
            if (x[i]!=x0)
                v.push_back((y[i]-y0)*1.0/(x[i]-x0));
            else
            if (y[i]-y0!=0)
                v.push_back(9999.9999);
    }
    sort(v.begin(),v.end());
    ll res = 0;
    for(int i=0;i<v.size();i++)
    if (v[i]!=v[i+1])
        res++;
    cout<<res;
    return 0;
}