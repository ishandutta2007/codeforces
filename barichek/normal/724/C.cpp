#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-10;

///---program start---///

#define int ll

int n,m,k;
map<pii,int> dist;
map<pii,bool> use;

void init_dist()
{
    use[mp(0,0)]=true;
    int xx=0,yy=0;
    bool is_dermo=false;
    int wh=1;
    while (!is_dermo)
    {
        int xx_=xx;
        int yy_=yy;
        //cout<<xx<<" "<<yy<<" "<<wh<<" !!!\n";
        if (wh==1)
        {
            int len=min(n-xx,m-yy);
            xx+=len;
            yy+=len;
            if (use[mp(xx,yy)])
                dist[mp(xx,yy)]=min(dist[mp(xx,yy)],dist[mp(xx_,yy_)]+len);
            else
                dist[mp(xx,yy)]=dist[mp(xx_,yy_)]+len,
                use[mp(xx,yy)]=true;
            if (xx==n) wh=2;
            else wh=4;
        }
        elif (wh==2)
        {
            int len=min(xx,m-yy);
            xx-=len;
            yy+=len;
            if (use[mp(xx,yy)])
                dist[mp(xx,yy)]=min(dist[mp(xx,yy)],dist[mp(xx_,yy_)]+len);
            else
                dist[mp(xx,yy)]=dist[mp(xx_,yy_)]+len,
                use[mp(xx,yy)]=true;
            if (yy==m) wh=3;
            else wh=1;
        }
        elif (wh==3)
        {
            int len=min(xx,yy);
            xx-=len;
            yy-=len;
            if (use[mp(xx,yy)])
                dist[mp(xx,yy)]=min(dist[mp(xx,yy)],dist[mp(xx_,yy_)]+len);
            else
                dist[mp(xx,yy)]=dist[mp(xx_,yy_)]+len,
                use[mp(xx,yy)]=true;
            if (xx==0) wh=4;
            else wh=2;
        }
        else
        {
            int len=min(n-xx,yy);
            xx+=len;
            yy-=len;
            if (use[mp(xx,yy)])
                dist[mp(xx,yy)]=min(dist[mp(xx,yy)],dist[mp(xx_,yy_)]+len);
            else
                dist[mp(xx,yy)]=dist[mp(xx_,yy_)]+len,
                use[mp(xx,yy)]=true;
            if (yy==0) wh=1;
            else wh=3;
        }
        //cout<<dist[mp(xx,yy)]<<" !\n";
        if (xx==0&&yy==0) is_dermo=true;
        if (xx==n&&yy==0) is_dermo=true;
        if (xx==0&&yy==m) is_dermo=true;
        if (xx==n&&yy==m) is_dermo=true;
    }
}

main()
{
    cin>>n>>m>>k;
    init_dist();
    while (k--)
    {
        int ans=maxll;
        int xx,yy;
        cin>>xx>>yy;
        int len;
        int xx_,yy_;

        len=min(xx,yy);
        xx_=xx-len;
        yy_=yy-len;
        if (use[mp(xx_,yy_)])
        //cout<<xx_<<" "<<yy_<<" !\n";
        ans=min(ans,dist[mp(xx_,yy_)]+len);
        //cout<<ans<<" 1!\n";

        len=min(n-xx,yy);
        xx_=xx+len;
        yy_=yy-len;
        if (use[mp(xx_,yy_)])
        //cout<<xx_<<" "<<yy_<<" !\n";
        ans=min(ans,dist[mp(xx_,yy_)]+len);
        //cout<<ans<<" 2!\n";

        len=min(xx,m-yy);
        xx_=xx-len;
        yy_=yy+len;
        if (use[mp(xx_,yy_)])
        //cout<<xx_<<" "<<yy_<<" !\n";
        ans=min(ans,dist[mp(xx_,yy_)]+len);
        //cout<<ans<<" 3!\n";

        len=min(n-xx,m-yy);
        xx_=xx+len;
        yy_=yy+len;
        if (use[mp(xx_,yy_)])
        //cout<<xx_<<" "<<yy_<<" !\n";
        ans=min(ans,dist[mp(xx_,yy_)]+len);
        //cout<<ans<<" 4!\n";

        cout<<(ans==maxll?-1:ans)<<"\n";
    }
}