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
#define get rgjeoig
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

signed main()
{
    int x,y;
    cin>>x>>y;
    if (y==1 && x>0)
    {
        cout<<"No";
        return(0);
    }
    if (x-(y-1)<0 || (x-(y-1))%2==1 || y==0)
    {
        cout<<"No";
    } else
    cout<<"Yes";
}
/*
*/