#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
//#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
string ans;
ll ur[2],nz,uk,l,r,p[400001][26],p1[400001],dp[26],kkee[26],a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
void push(ll v,ll tl,ll tr,ll zn)
{
    ll uuk=25;
    if(zn==-1)return;
    if(zn==0)uuk=0;
    ll tm=(tl+tr)/2;
    nz=(tm-tl+1);
    ll i;
    for(i=0;i<26;i++)dp[i]=p[v][i];
    for(i=0;i<26;i++)p[v*2+1][i]=0;
    for(i=0;i<26;i++)p[v*2][i]=0;
     while(1)
        {
            if(nz<=dp[uuk])
            {
                p[v*2][uuk]+=nz;
                dp[uuk]-=nz;
                break;
            }
            p[v*2][uuk]+=dp[uuk];
            nz-=dp[uuk];
            dp[uuk]=0;
            uuk+=ur[zn];
        }
    nz=tr-tm;
    while(1)
        {
            if(nz<=dp[uuk])
            {
                p[v*2+1][uuk]+=nz;
                dp[uuk]-=nz;
                break;
            }
            p[v*2+1][uuk]+=dp[uuk];
            nz-=dp[uuk];

            dp[uuk]=0;
            uuk+=ur[zn];
        }
        p1[v*2]=zn;
        p1[v*2+1]=zn;
        p1[v]=-1;
}
void build(ll v,ll tl,ll tr,ll pos,ll kk)
{
    p[v][kk]++;
    if(tl==tr)return;
    ll tm=(tl+tr)/2;
    if(pos<=tm)build(v*2,tl,tm,pos,kk);else build(v*2+1,tm+1,tr,pos,kk);
}
void getmd(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)return;
    ll i;
    if(tl==l && tr==r)
    {
        for(i=0;i<26;i++)
        {
            kkee[i]+=p[v][i];
            p[v][i]=0;
        }
        return;
    }
    push(v,tl,tr,p1[v]);
    ll tm=(tl+tr)/2;
    getmd(v*2,tl,tm,l,min(r,tm));
    getmd(v*2+1,tm+1,tr,max(l,tm+1),r);
}
void modify(ll v,ll tl,ll tr,ll l,ll r,ll zn)
{
    //cout << tl << " " << tr << " " << l << " " << r << endl;
    ll i;
    if(l>r)return;
    if(tl==l && tr==r)
    {
        nz=r-l+1;
        while(1)
        {
            if(nz<=kkee[uk])
            {
                p[v][uk]+=nz;
                kkee[uk]-=nz;
                break;
            }
            p[v][uk]+=kkee[uk];
            nz-=kkee[uk];
            kkee[uk]=0;
            uk+=ur[zn];
        }
        p1[v]=zn;
        return;
    }
    push(v,tl,tr,p1[v]);
    ll tm=(tl+tr)/2;
    modify(v*2,tl,tm,l,min(r,tm),zn);
    modify(v*2+1,tm+1,tr,max(l,tm+1),r,zn);
    for(i=0;i<26;i++)p[v][i]=p[v*2][i]+p[v*2+1][i];
}
ll get(ll v,ll tl,ll tr,ll pos)
{

    if(tl==tr)
    {
        ll i;
        for(i=0;i<26;i++)if(p[v][i]!=0)return i;
    }
    ll tm=(tl+tr)/2;
    push(v,tl,tr,p1[v]);
    if(pos<=tm)return get(v*2,tl,tm,pos);
    return get(v*2+1,tm+1,tr,pos);
}
int main(){
    ur[0]=1;
    ur[1]=-1;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(i=0;i<400000;i++)p1[i]=-1;
    for(i=1;i<=n;i++)
    {
        char cc;
        cin >> cc;
        build(1,1,n,i,ll(cc-'a'));
    }
    for(i=1;i<=m;i++)
    {
        ll kek;
        cin >> l >> r >> kek;
        kek=abs(kek-1);
        if(kek==0)uk=0;else uk=25;
        getmd(1,1,n,l,r);
        modify(1,1,n,l,r,kek);
    }
    for(j=1;j<=n;j++)
    {
        char aaa=char('a'+get(1,1,n,j));
        ans+=aaa;
    }
    cout << ans << endl;

return 0;
}