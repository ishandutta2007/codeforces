#include <bits/stdc++.h>
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using namespace std;
typedef long long ll;
typedef long double ld;

char rev(char c)
{
    if (c=='0')
        return('1'); else
        return('0');
}

signed main()
{
    int n,p;
    string st;
    cin>>n>>p>>st;
    bool ch=0;

    for (int i=0;i<st.size();i++)
    {
        if (st[i]=='.')
        {
            if (i+p<st.size())
            {
                if (st[i+p]=='.')
                {
                    st[i]='1';
                    st[i+p]='0';
                } else
                if (st[i+p]=='1')
                    st[i]='0'; else
                    st[i]='1';
            } else
            st[i]='1';
        } else
        {
            if (i+p<st.size() && st[i+p]=='.')
                st[i+p]=rev(st[i]);
        }
        if (i+p<st.size() && st[i+p]!=st[i])
            ch=1;
    }

    if (ch)
        cout<<st; else
        cout<<"No";
}