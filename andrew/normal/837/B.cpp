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
map < string, ll > mp;
string s,s1;
char cc[100][100],ckek;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n!=0)
    {
        if(n%2==1)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
ll fl,v[100000],dl,mx,c,sc,n,m,i,j,a[10000],b[100000],a1,b1,c1;
void check1()
{
if(n%3==0)
    {
        dl=n/3;
        ckek=cc[0][0];
        v[ckek]=1;
        for(i=0; i<dl; i++)
            for(j=0; j<m; j++)if(cc[i][j]!=ckek)
                {
                    fl=1;
                    break;
                }

        if(fl==1)return;

        i=dl;
        ckek=cc[i][0];
        if(v[ckek]==1)return;
        v[ckek]=1;
        dl+=dl;
        for(; i<dl; i++)
            for(j=0; j<m; j++)if(cc[i][j]!=ckek)
                {
                    fl=1;
                    break;
                }
        if(fl==1)return;
        ckek=cc[dl][0];
        if(v[ckek]==1)return;
        for(i=dl; i<n; i++)
            for(j=0; j<m; j++)if(cc[i][j]!=ckek)
                {
                    fl=1;
                    break;
                }
        if(fl==1)return;
        cout << "YES" << endl;
        exit(0);
        }

}
void chek()
{
                         fl=0;
        if(m%3==0)
    {
        dl=m/3;
        for(i=0; i<1000; i++)v[i]=0;
        ckek=cc[0][0];
        v[ckek]=1;
        for(i=0; i<n; i++)
            for(j=0; j<dl; j++)if(cc[i][j]!=ckek)
                {
                    fl=1;
                    break;
                }

        if(fl==1)return;
        i=dl;
        ckek=cc[0][i];
        if(v[ckek]==1)return;
        v[ckek]=1;
        ll jj=dl;
        dl+=dl;
        for(i=0; i<n; i++)
            for(j=jj; j<dl; j++)if(cc[i][j]!=ckek)
                {
                    fl=1;
                    break;
                }
        if(fl==1)return;

        ckek=cc[0][dl];
        if(v[ckek]==1)return;
        for(i=0; i<n; i++)
            for(j=dl; j<m; j++)if(cc[i][j]!=ckek)
                {
                    fl=1;
                    break;
                }
        if(fl==1)return;
        cout << "YES" << endl;
        exit(0);
    }

}
int main()
{

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)cin >> cc[i][j];
 check1();
 chek();
    cout << "NO" << endl;
    return 0;
}