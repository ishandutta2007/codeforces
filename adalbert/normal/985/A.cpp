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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

int p[200];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n/2;i++)
        cin>>p[i];

    sort(p+1,p+1+n/2);

    int res1=0,res2=0;

    for (int i=1;i<=n/2;i++)
        res1+=abs(i*2-1-p[i]);


    for (int i=1;i<=n/2;i++)
        res2+=abs(i*2-p[i]);

    cout<<min(res1,res2);
}