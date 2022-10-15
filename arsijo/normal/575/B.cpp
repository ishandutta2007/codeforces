#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define ld long double
#define ll long long
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define inf (int)1e9
#define pi pair<int,int>
#define y1 fdfs
using namespace std;
const int N=1e5+1,md=1e9+7;
int x,y,z,n,tin[N],tout[N],timer,up[N][20],l,ans;
int s[3][N],k,b[N*10],st[N*10];
vector<pair<int,int> >a[N];
void dfs(int v,int pr=-1)
{
    tin[v]=++timer;
    up[v][0]=pr;
    for(int i=1;i<=l;++i)
        up[v][i]=up[up[v][i-1]][i-1];
    for(int i=0;i<a[v].size();++i)
    {
        int to=a[v][i].x,z=a[v][i].y;
        if(to==pr) continue;
        dfs(to,v);
        if(!z) continue;
        if(z==1) ++s[1][to],--s[1][v];
            else ++s[2][to],--s[2][v];
    }
    tout[v]=timer;
}
inline char upper(int a,int b){
    return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}
int lca(int a,int b){
    if (upper(a,b)) return a;
    if (upper(b,a)) return b;
    for(int i=l;i>=0;i--)
        if (up[a][i]>0&&!upper(up[a][i],b))  a=up[a][i];
    return up[a][0];
}
void dfs_ans(int v,int pr=-1)
{
    for(int i=0;i<a[v].size();++i)
    {
        int to=a[v][i].x,z=a[v][i].y;
        if(to==pr) continue;
        dfs_ans(to,v);
        s[1][v]+=s[1][to];
        s[2][v]+=s[2][to];
        if(!z) continue;
        if(z==2){
            ans=(ans+st[s[2][to]-1])%md;
            ans=(ans-1+md)%md;
        }else{
            //if(s[1][to]-1>N-1) cout<<"K";
            ans=(ans+st[s[1][to]-1])%md;
            ans=(ans-1+md)%md;
        }
    }
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   // freopen("1.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin>>n;
    st[0]=1;
    for(int i=1;i<N*10;++i)
        st[i]=(st[i-1]+st[i-1])%md;
    for(int i=0;i<n-1;++i)
    {
        cin>>x>>y>>z;
        if(!z) {
            a[x].pb(mp(y,z));
            a[y].pb(mp(x,z));
        }else
        {
            a[x].pb(mp(y,1));
            a[y].pb(mp(x,2));
        }
    }
    while((1<<l)<n) ++l;
    dfs(1);
    cin>>k;
    b[0]=1;
    for(int i=1;i<=k;++i)
        cin>>b[i];
    for(int i=1;i<=k;++i)
    {
        z=lca(b[i-1],b[i]);
        ++s[1][b[i-1]];
        --s[1][z];

        ++s[2][b[i]];
        --s[2][z];
    }
    dfs_ans(1);
    cout<<ans;
}