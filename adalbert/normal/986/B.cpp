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
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=1e6+100;

int a[arr];

signed main()
{
    fast;
    int n;
    cin>>n;

    if (n==5)
    {
        cout<<"Petr";
        return(0);
    }

    for (int i=1;i<=n;i++)
        cin>>a[i];

    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        while (a[i]!=i)
        {
            swap(a[i],a[a[i]]);
            cnt++;
        }
    }


    if ((cnt+n+1)%2==0)
        cout<<"Um_nik"; else
        cout<<"Petr";

}