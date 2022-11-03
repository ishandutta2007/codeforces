#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
///-----------------------------------------------------------------------///
string st1,st2;
vector <pair<ll,ll> > vec;
ll xx[300000],yy[300000];
map <ll,vector <ll>  > pl,mn;
map<ll,ll> use[300000];
ll ans[300000];
///-----------------------------------------------------------------------///
int main()
{
    ll x,y,n,m,k;
    cin>>n>>m>>k;
    swap(n,m);
    x=0;
    y=0;
    ll np=1;
    use[n][m]=1;
    use[0][m]=1;
    use[n][0]=1;
    while (use[x][y]==0 )
    {
        //cout<<x<<' '<<y<<' '<<np<<'\n';
        vec.pb(mp(x,y));
        use[x][y]==1;
        if (np==1 )
        {
            ll p=min(n-x,m-y);
            if (p==n-x)
            {
                np=2;
            } else
            if (p==m-y)
            {
                np=4;
            }
            x+=p;
            y+=p;

        } else
        if (np==2 )
        {
            ll p=min(x,m-y);
            if (p==x)
            {
                np=1;
            } else
            if (p==m-y)
            {
                np=3;
            }
            x-=p;
            y+=p;

        } else
        if (np==3 )
        {
            ll p=min(x,y);
            if (p==x)
            {
                np=4;
            } else
            if (p==y)
            {
                np=2;
            }
            x-=p;
            y-=p;

        } else
        if (np==4 )
        {

            ll p=min(n-x,y);
            if (p==n-x)
            {
                np=3;
            } else
            if (p==y)
            {
                np=1;
            }
            x+=p;
            y-=p;

        }
    }
    vec.pb (mp(x,y));
    for (int i=1;i<=k;i++)
    {
        cin>>xx[i]>>yy[i];
        swap(xx[i],yy[i]);
        pl[+xx[i]-yy[i]].pb(i);
        mn[yy[i]+xx[i]].pb(i);
    }
    ll tep=0;
    for (int i=1;i<vec.size();i++)
    {
        //cout<<tep<<'!'<<'\n';
        //cout<<vec[i].fir<<' '<<vec[i].sec<<'\n';
        if ((vec[i-1].fir-vec[i].fir>0)==(vec[i-1].sec-vec[i].sec>0))
        {

            ll d=vec[i].fir-vec[i].sec;
            //cout<<'!'<<d<<'\n';
            for (int j=0;j<pl[d].size();j++)
            {
                if (ans[pl[d][j]]==0) ans[pl[d][j]]=tep+abs(xx[pl[d][j]]-vec[i-1].fir);
               // cout<<pl[d][j]<<'@'<<'\n';
            }

        } else
        {

            ll d=vec[i].fir+vec[i].sec;
           // cout<<'&'<<d<<'\n';
            for (int j=0;j<mn[d].size();j++)
            {
                 if (ans[mn[d][j]]==0) ans[mn[d][j]]=tep+abs(xx[mn[d][j]]-vec[i-1].fir);
                // cout<<mn[d][j]<<'@'<<'\n';
            }

        }
        tep+=abs(vec[i-1].fir-vec[i].fir);
    }
    for (int i=1;i<=k;i++) if (ans[i]!=0)
        cout<<ans[i]<<'\n'; else cout<<-1<<'\n';
}