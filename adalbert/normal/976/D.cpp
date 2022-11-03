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
const int arr=8e5;

int a[1000];
vector<pair<int,int> > ans;
int last=0;

void solve(int l, int r, int minuss)
{
    if (l>r)
    {
        last++;
        return;
    } else
    if (l==r)
    {
        int now=a[l]-minuss+1;
        for (int i=last+1;i<=last+now;i++)
            for (int j=i+1;j<=last+now;j++)
                ans.pb({i,j});

        last+=now;
        return;
    }

    solve(l+1,r-1,minuss+(a[l]-minuss));

    last+=a[r]-a[r-1];
    int pl=a[l]-minuss;

    for (int i=1;i<=last+pl;i++)
        for (int j=last+1;j<=last+pl;j++)
        if (i<j)
            ans.pb({i,j});
    last+=pl;
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    solve(1,n,0);

    cout<<ans.size()<<'\n';
    for (auto i:ans)
        cout<<i.fir<<' '<<i.sec<<'\n';
}