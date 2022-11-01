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

pair <ll,ll> a[110];
ll n,k,ansp,ans[110];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(k-a[i].first<0)
            break;
        ans[ansp]=a[i].second+1;
        ansp++;
        k-=a[i].first;  
    }
    cout<<ansp<<endl;
    for(int i=0;i<ansp;i++)
        cout<<ans[i]<<" ";
    return 0;
}