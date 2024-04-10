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
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;

    for (int i=1;i<st.size();i++)
        if (st[i]=='1' && st[i-1]=='1')
    {
        cout<<"No";
        return(0);
    }

    for (int i=0;i+1<st.size();i++)
        if (st[i]=='1' && st[i+1]=='1')
    {
        cout<<"No";
        return(0);
    }

    for (int i=0;i<st.size();i++)
        if (st[i]=='0')
        {
            if (i+1<st.size() && st[i+1]=='1')
                continue;
            if (i-1>=0 && st[i-1]=='1')
                continue;
            cout<<"No";
            return(0);
        }

    cout<<"Yes";
}
/*
*/