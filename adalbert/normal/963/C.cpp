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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int md=1e9+9;
const int arr=3e5+100;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
    {
        if (a>b)
            a%=b; else
            b%=a;
    }
    return(a+b);
}

int cntdil(int u)
{
    int res=0;
    for (int j=1;j*j<=u;j++)
    {
        if (u%j==0)
        {
            res++;
            if (u/j!=j)
                res++;
        }
    }
    return(res);
}

map<int,int> cnt;

bool bad(int a, int b, int c, int d)
{
    int cc=nsd(a,b);
    a/=cc;
    b/=cc;

    cc=nsd(c,d);
    c/=cc;
    d/=cc;

    return(a!=c || b!=d);
}

signed main()
{
    int n;
    cin>>n;

    map<int,vector<pair<int,int> > > mp;

    for (int i=1;i<=n;i++)
    {
        int w,h,c;
        cin>>w>>h>>c;
        mp[w].pb({h,c});
    }

    vector<vector<pair<int,int> > > vec;

    for (auto i:mp)
    {
        vec.pb(i.sec);
    }

    int mn=0;

    map<int,int> mp2;

    for (auto i:vec[mn])
    {
        mp2[i.fir]+=i.sec;
        cnt[i.fir]=i.sec;
    }

    for (int i=0;i<vec.size();i++)
        if (i!=mn)
        {
            vector<int> tutu;
            int con=0;
            for (auto j:vec[i])
            {
                if (mp2[j.fir]==0)
                {
                    cout<<0;
                    return(0);
                }
                con++;
                cnt[j.fir]=nsd(cnt[j.fir],j.sec);
            }

            if (con!=vec[mn].size())
            {
                cout<<0;
                return(0);
            }
        }

    int k=(*cnt.begin()).sec;

    for (auto j:cnt)
        k=nsd(k,j.sec);

    map<int,int> ok;

    for (auto j:vec[mn])
        ok[j.fir]=j.sec/k;

    for (int i=0;i<vec.size();i++)
    {
        sort(vec[i].begin(),vec[i].end());
    }

    for (int i=1;i<vec.size();i++)
        for (int j=1;j<vec[i].size();j++)
    {
        if (bad(vec[i-1][j-1].sec,vec[i-1][j].sec,vec[i][j-1].sec,vec[i][j].sec))
        {
            cout<<0;
            return(0);
        }
    }

    cout<<cntdil(k);
}