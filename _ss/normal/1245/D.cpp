#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=4e6+10,mod=1e9+7,inf=1e18,N=2e3+10;
struct ds
{
    ll u,v,w;
};

ds a[maxn];
int m,n,p[maxn];
vector<ds> ans;

int findr(int x)
{
    if (p[x]>0)
    {
        int tmp=findr(p[x]);
        p[x]=tmp;
        return tmp;
    }
    return x;
}

void merg(int u,int v)
{
    if (p[u]<p[v]) p[v]=u;
    else if (p[v]<p[u]) p[u]=v;
    else
    {
        p[v]=u;
        p[u]--;
    }
}

bool cmp(ds obj1,ds obj2) {return obj1.w<obj2.w;}

ll kruskal()
{
    sort(a+1,a+m+1,cmp);
    ll res=0;
    for (int i=1;i<=m && ans.size()<n;i++)
    {
        int u=a[i].u,v=a[i].v;
        int ru=findr(u),rv=findr(v);
        if (ru!=rv)
        {
            ans.pb(a[i]);
            merg(ru,rv);
            res+=a[i].w;
        }
    }
    return res;
}

pii col[N];
ll c[maxn],k[maxn];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>col[i].fi>>col[i].se;
    col[0]=mp(0,0);
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>k[i];
    m=1;
    for (int i=1;i<=n;i++) a[m++]={n+1,i,c[i]};
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) a[m++]={i,j,(k[i]+k[j])*(abs(col[i].fi-col[j].fi)+abs(col[i].se-col[j].se))};
    m--;
    n++;
    cout<<kruskal()<<endl;
    n--;
    vector<ll> res1;
    vector<ds> res2;
    for (int i=0;i<ans.size();i++)
        if (ans[i].u==n+1) res1.pb(ans[i].v);
        else res2.pb(ans[i]);
    cout<<res1.size()<<endl;
    for (int i=0;i<res1.size();i++) cout<<res1[i]<<" ";
    cout<<endl<<res2.size()<<endl;
    for (int i=0;i<res2.size();i++) cout<<res2[i].u<<" "<<res2[i].v<<endl;
    return 0;
}