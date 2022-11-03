#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh

#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int base=3;
const int INF=1e18;
const int md=1e9+9;

const int arr=1e6+100;

map<int,int> mp;

int ask(int u)
{
    cout<<u<<'\n';
    fflush(stdout);
    int res;
    cin>>res;
    if (res==0)
    {
        exit(0);
    }
    return(res);
}

int is_true[100000];

signed main()
{
    int m,n;
    cin>>m>>n;

    for (int i=1;i<=n;i++)
    {
        int now=ask(m);

        if (now==1)
            is_true[i]=0; else
            is_true[i]=1;
    }

    int l=1;
    int r=m;

    int pnow=1;
    while (r-l>1)
    {
        int d=(l+r)/2;

        int now=ask(d);

        if (!is_true[pnow])
            now=-now;

        if (now==1)
            l=d; else
            r=d;

        pnow++;
        if (pnow>n)
            pnow-=n;
    }

    for (int i=l;i<=r;i++)
        ask(i);
}