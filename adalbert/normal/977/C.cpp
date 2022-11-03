#include<bits/stdc++.h>
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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int arr=6e5;
int a[arr];
signed main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);
    if (k==0)
    {
        if (a[1]==1)
            cout<<-1; else
            cout<<1;
    } else
    if (k>n)
    {
        cout<<-1;
    } else
    if (a[k]==a[k+1])
    {
        cout<<-1;
    } else
    cout<<a[k];
}
/*
*/