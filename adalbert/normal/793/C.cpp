#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define int ll
#define m_p make_pair
#define sec second
typedef long long ll;
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdmn);


ld get_time(ld x, ld vx, ld x1)
{
    return((x1-x)/vx);
}
signed main()
{
    int n;
    cin>>n;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if (x1>x2) swap(x1,x2);
    if (y1>y2) swap(y1,y2);
    vector<pair<ld, int > > events;
    ld mx=0,mn=1e9;
    for (int i=1;i<=n;i++)
    {
        int x,y,vx,vy;
        cin>>x>>y>>vx>>vy;
        if (x<=x1 && vx<=0)
        {
            cout<<-1;
            return(0);
        }
        if (x>=x2 && vx>=0)
        {
            cout<<-1;
            return(0);
        }
        if (y<=y1 && vy<=0)
        {
            cout<<-1;
            return(0);
        }
        if (y>=y2 && vy>=0)
        {
            cout<<-1;
            return(0);
        }
        if (vx!=0)
        {
            mx=max(mx,min(get_time(x,vx,x1),get_time(x,vx,x2)));
            mn=min(mn,max(get_time(x,vx,x1),get_time(x,vx,x2)));
        }

        if (vy!=0)
        {
            mx=max(mx,min(get_time(y,vy,y1),get_time(y,vy,y2)));
            mn=min(mn,max(get_time(y,vy,y1),get_time(y,vy,y2)));
        }
    }
    if (mn<=mx)
    {
        cout<<-1;
        return(0);
    }
    cout<<fixed<<setprecision(9)<<mx;
}