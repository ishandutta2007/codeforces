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
const ll base=31;
const int arr=6e5;
const int md=1e9+9;

int hp[arr],dm[arr],pos[arr];

signed main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int sum=0;
    int mult=(1ll<<a);

    vector<pair<int,int> > pl;

    for (int i=1;i<=n;i++)
    {
        cin>>hp[i]>>dm[i];
        pl.pb({hp[i]-dm[i],i});
        sum+=dm[i];
    }

    sort(pl.begin(),pl.end());
    reverse(pl.begin(),pl.end());

    for (int i=0;i<pl.size();i++)
        pos[pl[i].sec]=i;
    pl[0].fir=max(ll(0),pl[0].fir);
    for (int i=1;i<pl.size();i++)
        pl[i].fir=max(ll(0),pl[i].fir)+pl[i-1].fir;

    int ans=sum;

    if (b==0)
    {
        cout<<ans;
        return(0);
    }

    for (int i=1;i<=n;i++)
    {
        int now=sum-dm[i]+hp[i]*mult;

        int pp=b-2;

        if (pos[i]<=pp)
        {
            pp++;
            now-=max(ll(0),hp[i]-dm[i]);
        }
        if (pp>=0)
            now+=pl[min(ll(pl.size()-1),pp)].fir;
        ans=max(ans,now);
    }

    cout<<ans;
}