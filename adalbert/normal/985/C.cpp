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

int a[arr];

signed main()
{
    int n,k,l;
    cin>>n>>k>>l;

    for (int i=1;i<=n*k;i++)
        cin>>a[i];

    sort(a+1,a+1+n*k);

    vector<int> starts,ends;

    for (int i=1;i<=n*k;i++)
        if (abs(a[1]-a[i])<=l)
        starts.pb(a[i]); else
        ends.pb(a[i]);

    int need=n-1;

    reverse(starts.begin(),starts.end());

    if (starts.size()<n)
    {
        cout<<0;
        return(0);
    }

    int ans=0;

    for (int i=1;i<=n;i++)
    {
        int can=k-1;
        ans+=starts.back();
        starts.pop_back();
        while(starts.size()>need && can--)
            starts.pop_back();
        need--;
    }

    cout<<ans;
}