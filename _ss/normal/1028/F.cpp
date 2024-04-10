#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;

int gcd(int t1,int t2)
{
    while (t2)
    {
        int r=t1%t2;
        t1=t2;
        t2=r;
    }
    return t1;
}

void compress(vector<pii> &vt)
{
    sort(all(vt));
    auto it=unique(all(vt));
    vt.resize(it-vt.begin());
}

vector<pii> candi;
int q,sl=1,cnt[N];

struct ds {int t,x,y; };
struct ds2
{
    vector<pii> poi;
    vector<int> on;
    vector<vector<int>> vt;
    void build()
    {
        compress(poi);
        on.resize(poi.size(),0);
        vt.resize(poi.size());
        for (int i=0;i<(int)poi.size();i++) vt[i].resize(poi.size(),-1);
        for (int i=0;i<(int)poi.size();i++)
            for (int j=0;j<(int)poi.size();j++)
            {
                pii np=mp(poi[i].fi+poi[j].fi,poi[i].se+poi[j].se);
                int tmp=gcd(np.fi,np.se);
                np.fi/=tmp;
                np.se/=tmp;
                tmp=lower_bound(all(candi),np)-candi.begin();
                if (tmp<(int)candi.size() && candi[tmp]==np) vt[i][j]=tmp;
            }
    }

    void add(pii p)
    {
        int t=lower_bound(all(poi),p)-poi.begin();
        on[t]=1;
        for (int i=0;i<(int)poi.size();i++)
            if (on[i])
            {
                int val=1+(i!=t);
                if (vt[t][i]!=-1) cnt[vt[t][i]]+=val;
            }
    }

    void del(pii p)
    {
        int t=lower_bound(all(poi),p)-poi.begin();
        for (int i=0;i<(int)poi.size();i++)
            if (on[i])
            {
                int val=1+(i!=t);
                if (vt[t][i]!=-1) cnt[vt[t][i]]-=val;
            }
        on[t]=0;
    }
};

ds query[N];
ds2 group[N];

void read()
{
    cin>>q;
    for (int i=1,t,x,y;i<=q;i++)
    {
        cin>>t>>x>>y;
        if (t==3)
        {
            int tmp=gcd(x,y);
            x/=tmp;
            y/=tmp;
        }
        query[i]={t,x,y};
    }
}

map<ll,int> id;

void process()
{
    for (int i=1;i<=q;i++)
        if (query[i].t==3) candi.pb(mp(query[i].x,query[i].y));
        else if (query[i].t==1)
        {
            int x=query[i].x,y=query[i].y,vt=id[x*x+y*y];
            if (!vt) id[x*x+y*y]=sl++,vt=sl-1;
            group[vt].poi.pb(mp(x,y));
        }
    compress(candi);
    sl--;
    for (int i=1;i<=sl;i++) group[i].build();
    int siz=0;
    for (int i=1;i<=q;i++)
    {
        int t=query[i].t,x=query[i].x,y=query[i].y;
        if (t==1) group[id[x*x+y*y]].add(mp(x,y)),siz++;
        if (t==2) group[id[x*x+y*y]].del(mp(x,y)),siz--;
        if (t==3)
        {
            int tmp=lower_bound(all(candi),mp(x,y))-candi.begin();
            cout<<siz-cnt[tmp]<<"\n";
        }
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    process();
    return 0;
}