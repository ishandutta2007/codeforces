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
    int n,q;
    cin>>n>>q;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }

    int sum=0;

    for (int i=1;i<=q;i++)
    {
        int k;
        cin>>k;
        sum+=k;
        if (a[n]<=sum)
        {
            sum=0;
        }

        int l=1;
        int r=n;

        while (r-l>1)
        {
            int d=(l+r)/2;
            if (a[d]>sum)
                r=d; else
                l=d;
        }
        while (a[l]<=sum)
            l++;
        cout<<n-l+1<<'\n';
    }
}