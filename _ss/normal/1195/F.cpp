#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;

vector<pii> a[N],Q[N];
vector<int> nex[N];
int n,bit[N],q,ans[N];

int gcd(int t1,int t2)
{
    while (t2)
    {
        int r=t1%t2;
        t1=t2;
        t2=r;
    }
    return abs(t1);
}

void read()
{
    cin>>n;
    for (int i=1,k;i<=n;i++)
    {
        cin>>k;
        vector<pii> p;
        p.resize(k);
        for (int j=0;j<k;j++) cin>>p[j].fi>>p[j].se;
        p.pb(p[0]);
        a[i].resize(k);
        nex[i].resize(k,0);
        for (int j=0;j<k;j++)
        {
            int x=p[j+1].fi-p[j].fi,y=p[j+1].se-p[j].se;
            int tmp=gcd(x,y);
            x/=tmp;
            y/=tmp;
            a[i][j]=mp(x,y);
        }
    }
    cin>>q;
    for (int i=1,l,r;i<=q;i++)
    {
        cin>>l>>r;
        Q[l].pb(mp(r,i));
    }
}

vector<pii> vt;

pii getvt(pii t) { return a[t.fi][t.se]; }

bool cmp(pii t1,pii t2)
{
    if (getvt(t1)==getvt(t2)) return t1.fi<t2.fi;
    return getvt(t1)<getvt(t2);
}

void add(int v,int val)
{
    for (int i=v;i<=n;i+=(i&-i)) bit[i]+=val;
}

int get(int v)
{
    int res=0;
    for (int i=v;i;i-=(i&-i)) res+=bit[i];
    return res;
}

void process()
{
    for (int i=1;i<=n;i++)
        for (int j=0;j<(int)a[i].size();j++) vt.pb(mp(i,j));
    sort(all(vt),cmp);
    add(vt[0].fi,1);
    for (int i=0;i<(int)vt.size()-1;i++)
        if (getvt(vt[i])==getvt(vt[i+1])) nex[vt[i].fi][vt[i].se]=vt[i+1].fi;
        else add(vt[i+1].fi,1);
    for (int i=1;i<=n;i++)
    {
        for (pii x : Q[i]) ans[x.se]=get(x.fi);
        add(i,-(int)a[i].size());
        for (int x : nex[i])
            if (x) add(x,1);
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}