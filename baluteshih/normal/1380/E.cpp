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

vector<int> tower[200005];
int boss[400005];

int finds(int x)
{
    if(x==boss[x]) return x;
    return boss[x]=finds(boss[x]);
}

int main()
{
    IOS();
    int n,m,ans=0,a,b;
    cin >> n >> m;
    for(int i=n+1;i<=n+m;++i)
        boss[i]=i;
    for(int i=1;i<=n;++i)
        cin >> boss[i],tower[boss[i]].pb(i),boss[i]+=n;
    for(int i=1;i<n;++i)
        if(finds(i)!=finds(i+1))
            ++ans;
    cout << ans << "\n";
    while(--m)
    {
        cin >> a >> b;
        if(SZ(tower[a])<SZ(tower[b]))
            tower[a].swap(tower[b]);
        vector<pii> state;
        for(int i:tower[b])
        {
            pii rt=pii(0,0);
            if(i<n&&finds(i)!=finds(i+1))
                rt.X=1;
            if(i>1&&finds(i)!=finds(i-1))
                rt.Y=1;
            tower[a].pb(i),state.pb(rt);
        }
        boss[b+n]=a+n;
        for(int i=0;i<SZ(state);++i)
        {
            pii rt=pii(0,0);
            if(tower[b][i]<n&&finds(tower[b][i])!=finds(tower[b][i]+1))
                rt.X=1;
            if(tower[b][i]>1&&finds(tower[b][i])!=finds(tower[b][i]-1))
                rt.Y=1;
            if(rt.X!=state[i].X)
                --ans;
            if(rt.Y!=state[i].Y)
                --ans;
        }
        cout << ans << "\n";
    }
}