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

string s;
int sum[1000005][3],boss[1000005];

int finds(int x)
{
    if(x==boss[x]) return x;
    return boss[x]=finds(boss[x]);
}

int main()
{
    IOS();
    int n;
    cin >> n >> s;
    for(int j=0;j<n;++j)
    {
        boss[j+1]=j+1;
        for(int k=0;k<3;++k)
            sum[j+1][k]=sum[j][k];
        if(s[j]=='?')
            ++sum[j+1][2];
        else
            ++sum[j+1][s[j]-'0'];
    }
    for(int i=1;i<=n;++i)
    {
        int ans=0;
        for(int j=0;j+i<=n;)
            if(sum[j+i][0]-sum[j][0]==0)
                ++ans,j+=i;
            else if(sum[j+i][1]-sum[j][1]==0)
                ++ans,j+=i;
            else
                boss[j]=finds(j+1),j=finds(j+1);
        cout << ans << " \n"[i==n];
    }
}