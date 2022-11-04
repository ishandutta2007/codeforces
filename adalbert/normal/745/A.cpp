#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
map <string,int> mp;
///-----------------------------------------------------------------------///
int main()
{
    string st;
    cin>>st;
    for (int i=1;i<=100;i++)
    {
        mp[st]++;
        string tep="";
        for (int i=1;i<st.size();i++)
            tep+=st[i];
        tep+=st[0];
        st=tep;
    }
    cout<<mp.size();
}