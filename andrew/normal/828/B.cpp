#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
const ll shl=1;
vector <ll> tt[1000];
set <ll> ss;
map < string , ll > mp;
string s,s1;
char a[1000][1000];
ll ans,c,sc,n,m,i,j,b[100000],a1,b1,c1,x;
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll mxy=-1e18,mny=1e18,mxx=-1e18,mnx=1e18;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
    {
        cin >> a[i][j];
        if(a[i][j]=='B')
        {
            mxx=max(mxx,j);
            mnx=min(mnx,j);
            mny=min(mny,i);
            mxy=max(mxy,i);
        }
    }
    if(mxx==-1e18)
    {
        cout << 1 << endl;
        return 0;
    }
    ll dl1=mxx-mnx+1,dl2=mxy-mny+1;
    //cout << dl1 << " " << dl2 << endl;;
    for(i=mny;i<=mxy;i++)for(j=mnx;j<=mxx;j++)if(a[i][j]=='W')ans++;
    if(dl1>dl2)
    {
        if(n<dl1)
        {
            cout << -1 << endl;
            return 0;
        }
        ans+=dl1*(dl1-dl2);
    }else
    if(dl2>dl1)
    {
        if(m<dl2)
        {
            cout << -1 << endl;
            return 0;
        }
        ans+=dl2*(dl2-dl1);
    }
    cout << ans << endl;
    return 0;
}