#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define int ll
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int a[100],b[100];
signed main()
{
    string st;
    int k;
    cin>>st>>k;
    /*if (st=="0")
    {
        cout<<0;
        return(0);
    }*/
    reverse(st.begin(),st.end());
    int now=0;
    int ans=0;
    while(k)
    {
        if (st[now]=='0') k--; else
            ans++;
        now++;
        if (now==st.size())
        {
            cout<<st.size()-1;
            return(0);
        }
    }
    cout<<ans;

}