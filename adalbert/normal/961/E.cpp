#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int v[1000000];

void pluss(int i, int tl, int tr, int x, int y)
{
    if (tl==tr)
    {
        v[i]+=y;
        return;
    }

    int d=(tl+tr)/2;
    if (x<=d)
        pluss(i*2,tl,d,x,y); else
        pluss(i*2+1,d+1,tr,x,y);
    v[i]=v[i*2]+v[i*2+1];
}

int get(int i, int tl, int tr, int l, int r)
{
    if (l>r)
        return(0);
    if (tl>=l && tr<=r)
        return(v[i]);
    if (tl>r || tr<l)
        return(0);
    int d=(tl+tr)/2;

    return(get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r));
}

int a[300000];
map<int,vector<int> > mp;

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]].pb(i);
        pluss(1,1,n,i,1);
    }

    int ans=0;

    for (int i=1;i<=n;i++)
    {
        ans+=get(1,1,n,1,min(i-1,a[i]));
        for (auto j:mp[i])
            pluss(1,1,n,j,-1);
    }

    cout<<ans;
}
/*
6
0 1
0 -1
1 1
1 -1
-1 -1
-1 1
*/