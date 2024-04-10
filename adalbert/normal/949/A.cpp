#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5;

signed main()
{
    string st;
    cin>>st;
    set<int> setik1,setik0;

    for (int i=0;i<st.size();i++)
        if (st[i]=='0')
        setik0.insert(i); else
        setik1.insert(i);

    vector<vector<int> > ans;

    while (!(setik0.empty() && setik1.empty()))
    {
        if (setik0.empty())
        {
            cout<<-1;
            return(0);
        }
        int now=*setik0.begin();
        setik0.erase(now);
        vector<int> vec;
        vec.pb(now+1);
        while(1)
        {
            auto it=setik1.upper_bound(now);
            if (it==setik1.end())
                break;
            auto it2=setik0.upper_bound(*it);
            if (it2==setik0.end())
                break;
            now=*it2;
            vec.pb((*it)+1);
            vec.pb((*it2)+1);

            setik1.erase(*it);
            setik0.erase(*it2);
        }
        ans.pb(vec);
    }

    cout<<ans.size()<<'\n';
    for (auto i:ans)
    {
        cout<<i.size()<<' ';
        for (auto j:i)
            cout<<j<<' ';
        cout<<'\n';
    }
}