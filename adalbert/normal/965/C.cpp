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

const int arr=3e5+100;
const int base=31;

int a[300][300],cnt[300][300];

int up(int a, int b)
{
    return(a/b+(a%b!=0));
}

signed main()
{
    int n,k,m,d;
    cin>>n>>k>>m>>d;

    int ans=0;

    for (int cnt=1;cnt<=d;cnt++)
    {
        int l=1;
        int r=m;

        while (r-l>1)
        {
            int d=(l+r)/2;
            //cout<<"@"<<up(n/d,k)<<' '<<d<<'\n';
            if (up(n/d,k)<cnt)
                r=d; else
                l=d;
        }

        while (r!=0 && up(n/r,k)<cnt)
            r--;

        if (r!=0 && up(n/r,k)==cnt)
            ans=max(ans,up(n/r,k)*r);
    }

    cout<<ans;
}