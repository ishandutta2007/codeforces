
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=7e5;

struct Node
{
    int zn;
    int l, r;

    Node()
    {
        zn=0;
        l=0;
        r=0;
    }
};

Node v[5*arr];

int last;

int get(int i, int tl, int tr, int l, int r)
{
    if (i==0)
        return(0);
    if (tl>r || tr<l)
        return(0);
    if (tl>=l && tr<=r)
        return(v[i].zn);

    int d=(tl+tr)/2;
    return(max(get(v[i].l,tl,d,l,r),get(v[i].r,d+1,tr,l,r)));
}

void change(int i, int tl, int tr, int x, int y)
{
    if (tl==tr)
    {
        v[i].zn=max(v[i].zn,y);
        return;
    }

    int d=(tl+tr)/2;
    if (x<=d)
    {
        if (v[i].l==0)
            v[i].l=++last;
        change(v[i].l,tl,d,x,y);
    } else
    {
        if (v[i].r==0)
            v[i].r=++last;
        change(v[i].r,d+1,tr,x,y);
    }

    v[i].zn=max(v[v[i].l].zn,v[v[i].r].zn);
}

int root[arr];

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        root[i]=i;
    last=n+1;

    int ans=0;

    while (m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int res=get(root[a],1,100000,1,c);
        res++;
        change(root[b],1,100000,c,res);
        ans=max(ans,res);
    }

    cout<<ans;
}