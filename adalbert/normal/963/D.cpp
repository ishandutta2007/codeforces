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
#define int ll
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int arr=3e5+100;
const int base=31;

int step[arr],hesh[arr],cnt[arr],ln[arr],rev[arr];

map<int,int> ask[arr];

int bpow(int a, int b)
{
    if (b==0)
        return(1);
    if (b%2)
        return(bpow(a,b-1)*a); else
        return(bpow(a*a,b/2));
}
string st;
int get(int l, int r)
{
    return((hesh[r]-hesh[l-1]))*step[st.size()-r];
}

vector<int> vec[arr];

signed main()
{
    fast;

    cin>>st;

    step[0]=1;
    rev[0]=1;
    for (int i=1;i<arr;i++)
    {
        step[i]=step[i-1]*base;
    }

    for (int i=1;i<=st.size();i++)
    {
        hesh[i]=(hesh[i-1]+(st[i-1]-'a'+1)*step[i]);
    }

    int q;
    cin>>q;
    int n=st.size();
    for (int i=1;i<=q;i++)
    {
        string st;
        cin>>cnt[i]>>st;
        ln[i]=st.size();
        int now=0;

        for (int i=1;i<=st.size();i++)
        {
            now=(now+(st[i-1]-'a'+1)*step[i]);
        }

        now*=step[n-st.size()];
        ask[st.size()][now]=i;
    }

    for (int len=0;len<=st.size();len++)
        if (!ask[len].empty())
        {
            for (int j=1;j+len-1<=st.size();j++)
            {
                int now=get(j,j+len-1);

                if (ask[len].count(now))
                {

                    vec[ask[len][now]].pb(j);
                }
            }
        }

    for (int i=1;i<=q;i++)
    {
        if (vec[i].size()<cnt[i])
            cout<<-1<<'\n'; else
        {
            int res=1e9;
            for (int j=0;j+cnt[i]-1<vec[i].size();j++)
                res=min(res,vec[i][j+cnt[i]-1]-vec[i][j]+ln[i]);
            cout<<res<<'\n';
        }
    }
}