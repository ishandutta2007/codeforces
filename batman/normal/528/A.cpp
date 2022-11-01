//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (222*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ll w,h,n,b[N],maxv,maxh;
char a[N];
set <ll> V,H;
vector <ll> ans;
int Sa1378
{ 
    ///////////
    IB
    cin>>w>>h>>n;
    V.insert(0);
    V.insert(h);
    H.insert(0);
    H.insert(w);
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]=='H')
            V.insert(b[i]);
        else
            H.insert(b[i]); 
    }
    //////////
    set <ll>::iterator it=V.begin(),it2;
    it2=++it;
    it--;
    while(it2!=V.end())
    {
        maxv=max(maxv,*it2-*it);
        it++;
        it2++;
    }
    it=H.begin();
    it2=++H.begin();
    while(it2!=H.end())
    {
        maxh=max(maxh,*it2-*it);
        it++;
        it2++;
    }
    ans.push_back(maxv*maxh);
    for(int i=n-1;i>0;i--)
    {
        if(a[i]=='H')
        {
            it=V.find(b[i]);
            it2=++it;
            it--,it--;
            maxv=max(maxv,*it2-*it);
            V.erase(b[i]);
        }
        else
        {
            it=H.find(b[i]);
            it2=++it;
            it--,it--;
            maxh=max(maxh,*it2-*it);
            H.erase(b[i]);
        }
        ans.push_back(maxv*maxh);
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<endl;
    return 0;
}