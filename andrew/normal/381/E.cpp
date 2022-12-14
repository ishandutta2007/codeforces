#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define pll pair <ll,ll>
#define endl "\n"
string s;
const ll maxn=1000000;
char cc;
ll st,res,lv[3000002],pos,rv[3000002],l,r,k,tf,skob[3000002],n,m,i,j,ans,sc,fl,kek,x,dp,a[1000],b[1000];
void build(ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
        if(s[tl-1]==')') rv[v]++;
        else lv[v]++;
        return;
    }
    ll tm=(tr+tl)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    ll mi=min(lv[v*2],rv[v*2+1]);
    skob[v]=skob[v*2]+skob[v*2+1]+mi*2;
    lv[v]=lv[v*2]+lv[v*2+1]-mi;
    rv[v]=rv[v*2]+rv[v*2+1]-mi;
}
void get(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)return;
    if(tl==l and r==tr)
    {
        //cout<<lef[v]<<" "<<skob[v]<<" "<<righ[v]<<endl;
        ll t=min(tf,rv[v]);
        tf+=lv[v];
        tf-=t;
        res+=skob[v]+t*2;
        return;
    }
    ll tm=(tr+tl)/2;
    get(v*2,tl,tm,l,min(tm,r));
    get(v*2+1,tm+1,tr,max(l,tm+1),r);
}
int main()
{

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n=s.size();
    build(1,1,n);
    cin >> m ;
    for(i=0; i<m; i++)
    {
        cin >> l >> r;
        res=0;
        tf=0;
        get(1,1,n,l,r);
        cout << res << endl;
    }
    return 0;
}