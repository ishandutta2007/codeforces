#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
///-----------------------------------------------------------------------///
int  main()
{
    int n,k;
    cin>>n>>k;
    string st;
    cin>>st;
    int pos;
    for (int i=0;i<st.size();i++)
    {
        if (st[i]=='G') pos=i;
    }
    int tep=pos;
    bool ch=1;
    while (tep<n && ch)
    {
        tep+=k;
        if (tep<n)
        {
            if (st[tep]!='#') st[tep]='.'; else ch=0;
        }
    }
    tep=pos;
    ch=1;
    while (tep>=0 && ch)
    {
        tep-=k;
        if (tep>=0)
        {
            if (st[tep]!='#') st[tep]='.'; else ch=0;
        }
    }
    for (int i=0;i<st.size();i++)
        if (st[i]=='T')
    {
        cout<<"NO";
        return(0);
    }
    cout<<"YES";
}