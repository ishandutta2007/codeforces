#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh

#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int base=3;
const int INF=1e18;
const int md=1e9+9;

const int arr=1e6+100;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b)
        a%=b; else
        b%=a;

    return(a+b);
}

signed main()
{
    int n,k;
    cin>>n>>k;

    int tutu=k;

    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        tutu=nsd(a,tutu);
    }

    vector<int> ans;

    int start=0;

    while (start<k)
    {
        ans.pb(start);
        start+=tutu;
    }

    cout<<ans.size()<<'\n';
    for (auto i:ans)
        cout<<i<<' ';
}