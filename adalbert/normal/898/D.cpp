#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=500000;

int a[arr];

signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    vector<int> vec;
    for (int i=1;i<=k;i++)
        vec.pb(-1e9);

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        vec.pb(a[i]);
        if (vec[vec.size()-1]-vec[vec.size()-k]+1<=m)
            vec.pop_back(),ans++;
    }

    cout<<ans;
}