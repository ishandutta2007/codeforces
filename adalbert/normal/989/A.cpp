#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using namespace std;
typedef long long ll;
typedef long double ld;

signed main()
{
    string st;
    cin>>st;

    for (int i=0;i+2<st.size();i++)
    {
        if (st[i]!='.' && st[i+1]!='.' && st[i+2]!='.')
            if (st[i]!=st[i+1] && st[i]!=st[i+2] && st[i+1]!=st[i+2])
        {
            cout<<"Yes\n";
            return(0);
        }
    }

    cout<<"No";
}