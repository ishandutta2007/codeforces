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
const int arr=1e6+100;

int color[arr],cost[arr],sum[arr];
vector<int> vec[arr];
int use[arr];
int get(int u)
{
    if (color[u]==u)
        return(u); else

        return(color[u]=get(color[u]));
}

signed main()
{
    fast;
    int n;
    cin>>n;
    vector<pair<int,int> > vv;

    for (int i=1;i<=n;i++)
    {
        cin>>cost[i];
        vv.pb({cost[i],i});
    }
    sort(vv.begin(),vv.end());

    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    for (int i=1;i<=n;i++)
    {
        color[i]=i;
        sum[i]=1;
    }

    int ans=0;
    for (auto i:vv)
    {
        int now=1;
        int allsum=0;
        for (auto j:vec[i.sec])
        if (use[j])
        {
            int c=get(j);
            now+=sum[c];
            now+=sum[c]*allsum;
            allsum+=sum[c];
            int a=get(i.sec);
            if (rand()%2)
                swap(a,c);
            color[a]=c;
            sum[c]+=sum[a];
        }
        ans+=now*i.fir;
        use[i.sec]=1;
    }

    for (int i=1;i<=n;i++)
    {
        color[i]=i;
        sum[i]=1;
        use[i]=0;
    }
    reverse(vv.begin(),vv.end());

    for (auto i:vv)
    {
        int now=1;
        int allsum=0;
        for (auto j:vec[i.sec])
        if (use[j])
        {
            int c=get(j);
            now+=sum[c];
            now+=sum[c]*allsum;
            allsum+=sum[c];
            int a=get(i.sec);
            if (rand()%2)
                swap(a,c);
            color[a]=c;
            sum[c]+=sum[a];
        }
        ans-=now*i.fir;
        use[i.sec]=1;
    }

    cout<<ans;
}