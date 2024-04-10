#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int a[300][300];
int n,m;

bool check(int l1, int r1, int l2, int r2)
{
    int res=1;
    for (int i1=l1;i1<=r1;i1++)
    {
        int i2=r2-i1+1;
        for (int j=1;j<=m;j++)
            res&=(a[i1][j]==a[i2][j]);
    }
    return(res);
}

signed main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];

    while (n%2==0 && check(1,n/2,n/2+1,n))
        n/=2;
    cout<<n;
}