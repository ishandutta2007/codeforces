////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (2*1000*1000*1000)
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("milk3.in");
ofstream fout("milk3.out");
ll cnt1,cnt2,x,y;
int main()
{ 

    cin>>cnt1>>cnt2>>x>>y;
    ll l=1,r=N;
    while(r>l)
    {
        ll mid=(l+r)/2;
        if(cnt1<=mid-mid/x && cnt2<=(mid-mid/y) && cnt1+cnt2<=mid-mid/(x*y))
            r=mid;
        else
            l=mid+1;    
    }
    cout<<r<<endl;
    
    return 0;
}