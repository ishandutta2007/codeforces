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
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;

const int arr=2e5;

int a[arr],pref[arr],suf[arr];

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }

    swap(n,m);

    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];

    vector<int> vec;
    vec.pb(-1e9);

    for (int i=1;i<=n;i++)
    {
        if (a[i]>=vec.back())
        {
            vec.pb(a[i]);
            pref[i]=vec.size()-1;
        } else
        {
            int p=upper_bound(vec.begin(),vec.end(),a[i])-vec.begin();
            vec[p]=a[i];
            pref[i]=p;
        }
    }

    vec.clear();
    vec.pb(-1e9);

    for (int i=n;i>=1;i--)
    {
        if (a[i]>=vec.back())
        {
            vec.pb(a[i]);
            suf[i]=vec.size()-1;
        } else
        {
            int p=upper_bound(vec.begin(),vec.end(),a[i])-vec.begin();
            vec[p]=a[i];
            suf[i]=p;
        }

    }

    int ans=0;

    for (int i=1;i<=n;i++)
        ans=max(ans,pref[i]+suf[i]-1);

    cout<<ans;
}