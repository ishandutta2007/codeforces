#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
typedef long long ll;
using namespace std;
vector <ll> tt[1000];
string dop="URDL";
pll p[1000][1000];
ll ans[5];
pll q[1000000];
ll q2,q1,stn,v[1000][1000],fl,i,j,n,m,k,sc,s,dp,x,a[100000],b[100000],a1,b1,c1,y;
char vivod[1000000];
char kek[1000][1000];
void fout(char s)
{
    cout << s << endl;
    fflush(stdout);
}
void add(ll y,ll x,ll fl)
{
    if(y<1 || x<1 || y>n || x>m || kek[y][x]=='*' || v[y][x])return;
    v[y][x]=fl;
    p[y][x]=q[q2];
    q[q1]=m_p(y,x);
    q1++;
}
int main() {
ans[1]=0;
ans[2]=1;
ans[3]=2;
ans[4]=3;
ll x1=1,y1=1;
    // set < ll > :: iterator kek=s.begin;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin >> kek[i][j];
    y1=x1=1;
    q[0]=m_p(-1,-1);
    add(x1,y1,1);
    while(q1!=q2)
    {
        ll yy=q[q2].fi,xx=q[q2].se;
        add(yy+1,xx,3);
        add(yy-1,xx,1);
        add(yy,xx+1,2);
        add(yy,xx-1,4);
        q2++;
    }
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(kek[i][j]=='F')
    {
        y=i;
        x=j;
        break;
    }
    while(y!=-1 && x!=-1)
    {
        stn++;
        vivod[stn]=ans[v[y][x]];
        ll yy=p[y][x].fi,xx=p[y][x].se;
        y=yy;
        x=xx;
    }
    reverse(vivod+1,vivod+stn+1);
    for(i=2;i<=stn;i++)
    {
        //cout << i << " "
        stop:
        ll yy=y1,xx=x1;
        fout(dop[vivod[i]]);
        cin >> x1 >> y1;
        if(x1==xx && y1==yy)
        {
            ll kkeekk=vivod[i]+1;
            if(kkeekk>2)kkeekk-=2;
            kkeekk--;
            swap(dop[kkeekk],dop[kkeekk+2]);
            goto stop;
        }
    }
    return 0;
}