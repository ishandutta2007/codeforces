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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;

int a[arr];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    string t;
    cin>>t;
    t+='0';

    int last=0;
    for (int i=1;i<=n;i++)
        if (!(t[i-1]-'0'))
        {
            sort(a+last+1,a+i+1);
            last=i;
        }

    for (int i=1;i<=n;i++)
        if (a[i]!=i)
    {
        cout<<"NO";
        return(0);
    }
    cout<<"YES";
}
/*
2
set physicsexercise 2
query physicsexercise
*/