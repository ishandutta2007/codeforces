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

signed main()
{
    fast;
    int n;
    cin>>n;

    set<string> setik;

    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        sort(st.begin(),st.end());

        string res="";
        res+=st[0];
        for (int i=1;i<st.size();i++)
            if (st[i]!=st[i-1])
            res+=st[i];
        setik.insert(res);
    }

    cout<<setik.size()<<'\n';
}