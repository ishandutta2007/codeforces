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
void change(string st, string ch)
{

}
///-----------------------------------------------------------------------///
int  main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
    string s="";
    ll i=0;
    while (i<st.size())
    {
        if (i+2<n)
        {
            if (st[i]=='o' && st[i+1]=='g' && st[i+2]=='o')
            {
                s+="***";
                i+=3;
                //cout<<i<<'\n';
                bool ch=1;
                while (ch && i+1<n)
                {
                    if (st[i]=='g' && st[i+1]=='o') i+=2; else ch=0;
                }
            }
            else
        {
            s+=st[i];
            i++;
        }
        } else
        {
            s+=st[i];
            i++;
        }

    }
    cout<<s;
}