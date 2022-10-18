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

ll ans=0;
int a[200005],b[200005],x,y,k;

void dst(int l,int r)
{
    int val=*max_element(a+l,a+r+1);
    if(r-l+1<k)
    {
        if(val>max(a[l-1],a[r+1]))
            cout << "-1\n",exit(0);
        else
            ans+=(ll)(r-l+1)*y;
    }
    else if((ll)k*y<(ll)x)
    {
        if(val>max(a[l-1],a[r+1]))
            ans+=(ll)(r-l+1-k)*y+x;
        else
            ans+=(ll)(r-l+1)*y;
    }
    else
        ans+=(ll)(r-l+1)%k*y+(ll)(r-l+1)/k*x;
}

int main()
{
    IOS();
    int n,m,lst,nw;
    cin >> n >> m;
    cin >> x >> k >> y;
    for(int i=1;i<=n;++i)
        cin >> a[i];
    for(int j=1;j<=m;++j)
        cin >> b[j];
    lst=1,nw=1;
    for(int i=1;i<=m;++i)
    {
        while(nw<=n&&a[nw]!=b[i])
            ++nw;
        if(nw>n)
           return cout << "-1\n",0;
        dst(lst,nw-1);
        lst=nw+1;
    }
    if(lst<=n)
        dst(lst,n);
    cout << ans << "\n";
}