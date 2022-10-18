#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

string mp[1005];
int boss[1500005],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int vis[1500005],n,m,C;

int finds(int x)
{
    if(x==boss[x]) return x;
    return boss[x]=finds(boss[x]);
}

void Union(int x,int y)
{
    x=finds(x),y=finds(y);
    boss[x]=y;
}

int check(int x,int y)
{
    return !(x<=0||y<=0||x>n||y>m||mp[x][y]=='.');
}

void Union(int x1,int y1,int x2,int y2)
{
    Union(x1*C+y1,x2*C+y2);
}

int finds(int x,int y)
{
    return finds(x*C+y);
}

int main()
{
    IOS();
    int flagn=0,flagm=0,ans=0;
    cin >> n >> m,C=m+1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            boss[i*C+j]=i*C+j;
    for(int i=1;i<=n;++i)
        cin >> mp[i],mp[i].insert(mp[i].begin(),'.'),mp[i].pb('.');
    mp[0].resize(m+2,'.'),mp[n+1].resize(m+2,'.');
    for(int i=1;i<=n;++i)
    {
        int tmp=0;
        for(int j=0;j<=m;++j)
            if(((mp[i][j]=='.')^(mp[i][j+1]=='.'))==1)
                ++tmp;
        if(tmp==0)
            flagn=1;
        else if(tmp>2)
            return cout << "-1\n",0;
    }
    for(int j=1;j<=m;++j)
    {
        int tmp=0;
        for(int i=0;i<=n;++i)
            if(((mp[i][j]=='.')^(mp[i+1][j]=='.'))==1)
                ++tmp;
        if(tmp==0)
            flagm=1;
        else if(tmp>2)
            return cout << "-1\n",0;
    }    
    if((flagn^flagm)==1)
        return cout << "-1\n",0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            for(int k=0;k<4;++k)
                if(mp[i][j]=='#'&&check(i+dx[k],j+dy[k]))
                    Union(i,j,i+dx[k],j+dy[k]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(mp[i][j]=='#'&&!vis[finds(i,j)])
                ++ans,vis[finds(i,j)]=1;
    cout << ans << "\n";
}