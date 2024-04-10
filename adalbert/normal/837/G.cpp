#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld  long double
#define fir first
#define sec second
typedef long long ll;

const int arr=4e5;

struct Node
{
    int l,r;
    ll a,b,pusha,pushb;

    Node()
    {
        l=0;
        r=0;
        a=0;
        b=0;
        pusha=0;
        pushb=0;
    }
};

int cnt;
Node v[66*arr];

void make_push(int i, int tl, int tr)
{
    if (tl==tr) return;
    if (v[i].pusha==0 && v[i].pushb==0) return;

    int l=v[i].l;
    int r=v[i].r;
    ll pa=v[i].pusha;
    ll pb=v[i].pushb;
    int d=(tl+tr)/2;
    int nl=++cnt;
    int nr=++cnt;
    if (cnt>66*arr)
    {
        cout<<'#';
        exit(0);
    }
    v[nl]=v[l];
    v[nr]=v[r];
    l=nl;
    r=nr;
    v[i].l=l;
    v[i].r=r;

    v[l].a+=pa;
    v[r].a+=pa;
    v[l].b+=pb;
    v[r].b+=pb;
    v[l].pusha+=pa;
    v[l].pushb+=pb;
    v[r].pusha+=pa;
    v[r].pushb+=pb;

    v[i].pusha=0;
    v[i].pushb=0;
    if (cnt>66*arr)
    {
        cout<<'#';
        exit(0);
    }
}

void pluss(int i1, int i2, int tl, int tr, int l, int r, ll pa, ll pb)
{
    make_push(i1,tl,tr);
    v[i2]=v[i1];
    if (tl>r || tr<l) return;
    if (tl>=l && tr<=r)
    {
        v[i2].a+=pa;
        v[i2].b+=pb;
        v[i2].pusha+=pa;
        v[i2].pushb+=pb;
        return;
    }

    int d=(tl+tr)/2;
    if (l<=d)
    {
        v[i2].l=++cnt;
        pluss(v[i1].l,v[i2].l,tl,d,l,r,pa,pb);
    }
    if (d<r)
    {
        v[i2].r=++cnt;
        pluss(v[i1].r,v[i2].r,d+1,tr,l,r,pa,pb);
    }

    v[i2].a=max(v[v[i2].l].a,v[v[i2].r].a);
    v[i2].b=max(v[v[i2].l].b,v[v[i2].r].b);
}

pair<ll,ll> pluss(pair<ll,ll> i, pair<ll,ll> j)
{
    i.fir+=j.fir;
    i.sec+=j.sec;
    return(i);
}

pair<ll,ll> get(int i, int tl, int tr, int x)
{
    if (tl==tr) return(make_pair(v[i].a,v[i].b));


    int d=(tl+tr)/2;
    if (x<=d)
        return(pluss(get(v[i].l,tl,d,x),make_pair(v[i].pusha,v[i].pushb))); else
        return(pluss(get(v[i].r,d+1,tr,x),make_pair(v[i].pusha,v[i].pushb)));
}

int root[arr];

///---program start---///
signed main()
{
    fast;
    int n;
    cin>>n;
    root[0]=++cnt;
    int last=root[0];
    for(int i=1;i<=n;i++)
    {

        ll x1,x2,y1,a,b,y2;
        cin>>x1>>x2>>y1>>a>>b>>y2;
        if (x1>200000 || x2>200000) exit(1);
        root[i]=++cnt;
        pluss(last,root[i],0,210000,0,x1,0,y1);
        last=root[i];
        root[i]=++cnt;
        pluss(last,root[i],0,210000,x1+1,x2,a,b);
        last=root[i];
        root[i]=++cnt;
        pluss(last,root[i],0,210000,x2+1,210000,0,y2);
        last=root[i];
        if (cnt>ll(66)*arr)
        {
            exit(1);
        }
        //if (n==76600)
        //    cout<<'@';
        /*if ((get(root[i],0,210000,210000)).fir!=0)
        {
            cout<<'!';
            return(0);
        }*/
        if (cnt>66*arr)
        {
            cout<<'#';
            exit(0);
        }
    }

    int m;
    cin>>m;
    ll now=0;
    for (int i=1;i<=m;i++)
    {
        ll l,r,x;
        cin>>l>>r>>x;
        /*
        if (n==76600)
            cout<<x<<"!!!"<<'\n';
        */
        x=(now+x)%ll(1e9);
        x=min(x,ll(210000));
        l--;
        pair<ll,ll> p1=get(root[l],0,210000,x);
        pair<ll,ll> p2=get(root[r],0,210000,x);



        p2.fir-=p1.fir;
        p2.sec-=p1.sec;
        if (n==66636 && i==118116 && p2.fir*x+p2.sec==13683893640440)
            cout<<x<<"!!!"<<l<<'!'<<r<<'!'<<p2.fir<<'!'<<p2.sec<<'\n';
        cout<<p2.fir*x+p2.sec<<'\n';
        now=p2.fir*x+p2.sec;
        now%=ll(1e9);
    }
}