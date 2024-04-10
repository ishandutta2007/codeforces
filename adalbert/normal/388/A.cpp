#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define int ull
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int a[500];
int n;
bool check(int u)
{
    vector<int> vec;
    for (int i=1;i<=u;i++)
        vec.pb(1e9);

    for (int i=1;i<=n;i++)
    {
        int ok=0;
        for (int j=0;j<vec.size();j++)
            if (vec[j]!=0 && (((min(vec[j]-1,a[i]))>min(vec[ok]-1,a[i])) || vec[ok]==0))
            ok=j;
       // cout<<a[i]<<' '<<ok<<'\n';
        if (vec[ok]==0)
            return(0);
        vec[ok]=min(vec[ok]-1,a[i]);
    }

    return(1);
}

signed main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);



    for (int i=1;i<=n;i++)
        if (check(i))
    {
        cout<<i;
        return(0);
    }
}