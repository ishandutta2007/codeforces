#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
const ll shl=1;
const ll MAXN=1123456;
vector <pll> v[MAXN];
set <pll> st;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
stringstream ss;
char cc[4][4][4][4];
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
void check(ll x,ll y,ll x1,ll y1)
{
    ll fl=0;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
    {
        if(cc[x1][y1][i][j]=='.'){cc[x1][y1][i][j]='!';fl++;}
    }
    if(fl==0)
    {
        for(i=1;i<=3;i++)
            for(j=1;j<=3;j++)
            for(ll i1=1;i1<=3;i1++)
            for(ll j1=1;j1<=3;j1++) if(cc[i][j][i1][j1]=='.'){cc[i][j][i1][j1]='!';fl++;}
    }
    return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    for(ll i=1;i<=3;i++)
    {
        for(ll i1=1;i1<=3;i1++)
        {
            for(j=1;j<=3;j++)
            {
                for(ll i2=1;i2<=3;i2++)cin >> cc[i][j][i1][i2];
            }
        }
    }
    ll y;
    cin >> x >> y;
    ll x1=x/3;
    if(x%3)x1++;
    ll y1=y/3;
    if(y1%3)y1++;
    x%=3;
    if(x==0)x=3;
    y%=3;
    if(y==0)y=3;
    check(x1,y1,x,y);
    for(ll i=1;i<=3;i++)
    {
        for(ll i1=1;i1<=3;i1++)
        {
            for(j=1;j<=3;j++)
            {
                for(ll i2=1;i2<=3;i2++)cout << cc[i][j][i1][i2];
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}