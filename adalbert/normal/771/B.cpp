#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define pb push_back
#define ld long double
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
string st[100];
signed main()
{
    int n,k;
    int cnt=0;
    cin>>n>>k;
    vector<string> ans;
    vector<string> vec;
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
    {
        string now="";
        now+='A'+i;
        now+='a'+j;
        vec.pb(now);
    }
    sort(vec.begin(),vec.end());
    for (int i=1;i<=n-k+1;i++)
        cin>>st[i];
    if (st[1]=="YES")
    {
        for (int i=1;i<=k;i++)
            ans.pb(vec[i-1]);
        cnt=k-1;
    } else
    {
        for (int i=1;i<=k;i++)
            ans.pb(vec[i-1]);
        cnt=k-1;
        ans[0]=ans[1];
    }

    for (int i=2;i<=n-k+1;i++)
        if (st[i]=="NO") ans.pb(ans[ans.size()-k+1]); else
    {
        cnt++;
        ans.pb(vec[cnt]);
    }
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
}