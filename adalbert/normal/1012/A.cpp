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
const ll INF=1e18;
const int md=1e9+9;
const int arr=1e5+10;

int a[2*arr];


signed main()
{
    int n;
    cin>>n;
    n*=2;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);

    int ans=(a[n/2]-a[1])*(a[n]-a[n/2+1]);

    for (int i=1;i+n/2-1<=n;i++)
        ans=min(ans,(a[n]-a[1])*(a[i+n/2-1]-a[i]));

    cout<<ans;
}