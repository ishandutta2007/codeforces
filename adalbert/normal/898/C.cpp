#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=500000;

map<string, vector<string> > mp;

bool chek (string st1, string st2)
{
    if (st1.size()<st2.size())
        return(1); else
        return(0);
}

bool check(string st1, string st2)
{
    reverse(st1.begin(),st1.end());
    reverse(st2.begin(),st2.end());
    for (int i=0;i<st2.size();i++)
        if (st2[i]!=st1[i])
        return(0);
    return(1);
}

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        int k;
        cin>>k;
        while (k--)
        {
            string s;
            cin>>s;
            mp[st].pb(s);
        }
    }
    cout<<mp.size()<<'\n';
    for (auto i:mp)
    {
        cout<<i.fir<<' ';
        vector<string> vec=i.sec;
        sort(vec.begin(),vec.end(),chek);
        reverse(vec.begin(),vec.end());
        vector<string> res;

        for (int i=0;i<vec.size();i++)
        {
          //  cout<<vec[i]<<'\n';
            bool ch=1;
            for (int j=0;j<i;j++)
                if (check(vec[j],vec[i]))
                ch=0;
            if (ch)
                res.pb(vec[i]);
        }

        cout<<res.size()<<' ';
        for (auto i:res)
            cout<<i<<' ';
        cout<<'\n';
    }
}