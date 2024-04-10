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
const int md=998244353;
const int arr=3e5;

set<pair<int,int> > setik[arr];

vector<pair<int,int> > tutu;

int v[8*arr],m[8*arr],push[8*arr];
int n,q;

void update(int i, int mul, int pu, int l, int r)
{
    v[i]*=mul;
    v[i]+=pu*(r-l+1)%md;
    v[i]%=md;

    m[i]*=mul;
    m[i]%=md;
    push[i]*=mul;
    push[i]+=pu;
    push[i]%=md;
}

void make_push(int i, int tl, int tr)
{
    int d=(tl+tr)/2;
    update(i*2,m[i],push[i],tl,d);
    update(i*2+1,m[i],push[i],d+1,tr);

    m[i]=1;
    push[i]=0;
}

void mult(int i, int tl, int tr, int l, int r)
{

    if (l>r)
        return;
    if (tl>=l && tr<=r)
    {
        update(i,2,0,tl,tr);
        return;
    }
    if (tl>r || tr<l)
        return;

    make_push(i,tl,tr);

    int d=(tl+tr)/2;
    mult(i*2,tl,d,l,r);
    mult(i*2+1,d+1,tr,l,r);

    v[i]=v[i*2]+v[i*2+1];
    v[i]%=md;
}

void add(int i, int tl, int tr, int l, int r)
{

    if (l>r)
        return;
    if (tl>=l && tr<=r)
    {
        update(i,1,1,tl,tr);
        return;
    }
    if (tl>r || tr<l)
        return;

        make_push(i,tl,tr);

    int d=(tl+tr)/2;
    add(i*2,tl,d,l,r);
    add(i*2+1,d+1,tr,l,r);

    v[i]=v[i*2]+v[i*2+1];
    v[i]%=md;
}
int get(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
        return(v[i]);
    if (tl>r || tr<l)
        return(0);
    make_push(i,tl,tr);

    int d=(tl+tr)/2;
    return((get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r))%md);
}

void change(pair<int,int> p, int l, int r)
{
    l=max(l,p.fir);
    r=min(r,p.sec);
    mult(1,1,n,l,r);
    tutu.pb(p);
}

void add(int l, int r, int x)
{
    auto to=setik[x].lower_bound({l,-1e18});
    tutu.clear();
    if (to!=setik[x].begin())
    {
        to--;
        pair<int,int> now=*to;


        if (now.sec>=l)
        {
            change(now,l,r);
            setik[x].erase(now);
            l=now.fir;
            r=max(r,now.sec);

        }
    }

    while (1)
    {
        auto to=setik[x].lower_bound({l,-1e18});
        if (to==setik[x].end())
            break;
        if (to->fir>r)
            break;

        pair<int,int> now=*to;
        change(now,l,r);

        setik[x].erase(now);
        r=max(r,now.sec);
    }

    if (tutu.empty())
        add(1,1,n,l,r);


    for (int i=1;i<tutu.size();i++)
        add(1,1,n,tutu[i-1].sec+1,tutu[i].fir-1);

    if (!tutu.empty())
    {
        add(1,1,n,l,tutu[0].fir-1);
        add(1,1,n,tutu.back().sec+1,r);
    }

    setik[x].insert({l,r});
}

signed main()
{
    fast;
    for (int i=0;i<8*arr;i++)
        m[i]=1;

    cin>>n>>q;

    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            add(l,r,x);
        } else
        {
            int l,r;
            cin>>l>>r;
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }
}