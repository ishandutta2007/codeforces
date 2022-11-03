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

vector<int> vec[1000];
int cnt[10000];

signed main()
{
    string st;
    cin>>st;

    for (int i=0;i<st.size();i++)
    {
        vec[st[i]].pb(i);
    }

    ld ans=0;
    for (int i='a';i<='z';i++)
    {
        if (vec[i].empty())
            continue;
        int mx=0;
        for (int pl=1;pl<st.size();pl++)
        {
            int good=0;
            for (auto j:vec[i])
            {
                cnt[st[(j+pl)%st.size()]]++;
                if (cnt[st[(j+pl)%st.size()]]==1)
                    good++; else
                if (cnt[st[(j+pl)%st.size()]]==2)
                    good--;
            }
            mx=max(mx,good);
            for (auto j:vec[i])
            {
                cnt[st[(j+pl)%st.size()]]--;
            }
        }
        ans+=ld(vec[i].size())/ld(st.size())*(ld(mx)/ld(vec[i].size()));
    }

    cout<<fixed<<setprecision(9)<<ans;
}