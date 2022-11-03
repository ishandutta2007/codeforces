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

int cnt[arr];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }

    int start=1;

    for (int i=1;i<=n;i++)
        if (cnt[i]>2)
        start=i;

    for (int i=1;i<=n;i++)
        if (i!=start && cnt[i]>2)
    {
        cout<<"No";
        return(0);
    }

    vector<pair<int,int> > ans;

    for (int i=1;i<=n;i++)
        if (cnt[i]==1 && i!=start)
        ans.pb({i,start});

    cout<<"Yes\n";
    cout<<ans.size()<<'\n';
    for (auto i:ans)
        cout<<i.fir<<' '<<i.sec<<'\n';
}