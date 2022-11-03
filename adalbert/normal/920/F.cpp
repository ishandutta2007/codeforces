#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=4e5+100;

int dil[1200000],f[1200000];

int a[arr],v[4*arr];

int get(int i, int tl, int tr, int l,int r)
{
    if (tl>=l && tr<=r)
        return(v[i]);
    if (tl>r || tr<l)
        return(0);
    int d=(tl+tr)/2;
    return(get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r));
}

void change(int i, int tl, int tr, int x, int y)
{
    if (tl==tr)
    {
        v[i]=y;
        return;
    }

    int d=(tl+tr)/2;
    if (x<=d)
        change(i*2,tl,d,x,y); else
        change(i*2+1,d+1,tr,x,y);
    v[i]=v[i*2]+v[i*2+1];
}

signed main()
{
    fast;
    for (int i=2;i<=1e6;i++)
    {
        if (!dil[i])
        for (int j=2*i;j<=1e6;j+=i)
            dil[j]=i;
    }
    f[1]=1;
    for (int i=2;i<=1e6;i++)
    {
        if (dil[i]==0)
            f[i]=2; else
        {
            int c=0;
            int u=i;
            while (u%dil[i]==0)
            {
                u/=dil[i];
                c++;
            }
            f[i]=f[u]*(c+1);
        }

    }

    int n,m;
    cin>>n>>m;

    set<int> setik;
    for (int i=1;i<=n;i++)
        setik.insert(i);
    setik.insert(1e9);

    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<=n;i++)
        change(1,1,n,i,a[i]);

    while (m--)
    {
        int type;
        cin>>type;
        int l,r;
        cin>>l>>r;
        vector<int> add;

        if (type==1)
        {
            while (*setik.lower_bound(l)<=r)
            {
                int now=*setik.lower_bound(l);
                change(1,1,n,now,f[a[now]]);
                a[now]=f[a[now]];
                if (f[a[now]]!=a[now])
                    add.pb(now);
                setik.erase(now);
            }
            for (auto i:add)
                setik.insert(i);
        } else
        {
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }
}
/*
2
set physicsexercise 2
query physicsexercise
*/