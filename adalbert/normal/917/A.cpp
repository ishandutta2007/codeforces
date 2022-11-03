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

signed main()
{
    string st;
    cin>>st;
    int open=0;
    int cnt=0;

    int ans=0;

    for (int i=0;i<st.size();i++)
    {
        int cnt1=0,cnt2=0,cntok=0;
        for (int j=i;j<st.size();j++)
        {
            if (st[j]=='(')
                cnt1++; else
            if (st[j]==')')
                cnt2++; else
                cntok++,cnt2++;

            while (cnt2>cnt1 && cntok)
            {
                cntok--;
                cnt2--;
                cnt1++;
            }
            if (cnt2>cnt1)
                break;
            if (cnt1==cnt2)
                ans++;
        }
    }

    cout<<ans;
}