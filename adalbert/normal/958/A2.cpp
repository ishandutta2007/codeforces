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
typedef unsigned long long ull;
typedef long double ld;

const int arr=3e5;
const int base=257;
int md=1e9+100;

int hesh1[2010][2010],hesh2[2010][2010],h1[2010],h2[2010],step[arr],rstep[arr];

int get(int u, int l, int r)
{
    return((hesh2[u][r]-hesh2[u][l-1])%md+md)%md*rstep[l-1]%md;
}

int bpow(int u, int step)
{
    if (step==0)
    return(1);
    if (step%2)
        return(bpow(u,step-1)*u%md); else
        return(bpow(u*u%md,step/2));
}

string st1[3000],st2[3000];

int n,m;

bool check(int p1, int p2)
{
    for (int i=1;i<=m;i++)
        if (hesh1[p1+i-1][m]!=get(i,p2,p2+m-1))
        return(0);
    return(1);
}

bool simple(int u)
{
    for (int i=2;i*i<=u;i++)
        if (u%i==0)
        return(0);
    return(1);
}

signed main()
{

    md++;
    while (!simple(md))
        md++;
    fast;
    cin>>n>>m;

    step[0]=1;

    for (int i=1;i<=10000;i++)
    {
        step[i]=step[i-1]*base%md;
    }

    for (int i=0;i<=10000;i++)
    {
        rstep[i]=bpow(step[i],md-2);
    }



    for (int i=1;i<=n;i++)
    {
        cin>>st1[i];

        for (int j=1;j<=m;j++)
            hesh1[i][j]=(hesh1[i][j-1]+(st1[i][j-1]-'a'+1)*step[j])%md;
    }

    for (int i=1;i<=m;i++)
    {
        cin>>st2[i];

        for (int j=1;j<=n;j++)
            hesh2[i][j]=(hesh2[i][j-1]+(st2[i][j-1]-'a'+1)*step[j])%md;
    }

    for (int i=1;i+m-1<=n;i++)
    {
        h1[i]=0;
        int len=0;
        for (int j=1;j<=m;j++)
        {
            h1[i]+=hesh1[i+j-1][m]*step[len];
            h1[i]%=md;
            len+=m;
        }
    }

    for (int i=1;i+m-1<=n;i++)
    {
        h2[i]=0;
        int len=0;
        for (int j=1;j<=m;j++)
        {
            h2[i]+=get(j,i,i+m-1)*step[len];
            h2[i]%=md;
            len+=m;
        }


    }

    vector<pair<pair<int,int>,int> > vec;
    set<int> bad;
    for (int i=1;i+m-1<=n;i++)
    {
        int cnt=100;
        for (int j=m;j<=n;j++)
        if (h1[i]==h2[n-j+1] && cnt)
        {
            vec.pb({{i,n-j+1},h1[i]});
            cnt--;
        }
        cnt=100;
        for (int j=1;j+m-1<=n;j++)
        if (h1[i]==h2[j] && cnt)
        {
            vec.pb({{i,j},h1[i]});
            cnt--;
        }
    }



    random_shuffle(vec.begin(),vec.end());

    for (auto i:vec)
    {
        if (bad.count(i.sec))
            continue;
        if (check(i.fir.fir,i.fir.sec))
        {
            cout<<i.fir.fir<<' '<<i.fir.sec;
            return(0);
        }
    }

    exit(1);
}
/*
*/