#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

struct triple
{
  ll l,r,v;
};

ll lt[ml],rt[ml];
ll t[ml];
ll n,i,j,s,q;
vector <ll> x,w;
vector <triple> seg;
bool viv=false;

void change(ll v, ll tl, ll tr, ll num, ll nw)
{
if (tl<=num&&num<=tr)
  {
  t[v]+=nw;
  lt[v]+=(x[num]-x[tl]-num+tl)*nw;
  ll real_tr=min(tr, n-1);
  rt[v]+=(x[real_tr]-x[num]-real_tr+num)*nw;

  lt[v]%=mod;
  rt[v]%=mod;
  ll tm=tl+tr>>1;
  if (tl<tr)
    {
    change(2*v, tl, tm, num, nw);
    change(2*v+1, tm+1, tr, num, nw);
    }
  }
}

ll getr (ll l, ll r, ll v, ll tl, ll tr, ll num)
{
if (r<tl||tr<l)
  return 0;
if (l<=tl&&tr<=r)
  {
  ll ret=rt[v];
  ll real_tr=min(tr, n-1);
  ret+=((t[v]%mod)*(x[num]-x[real_tr]-num+real_tr));
  ret%=mod;
  return ret;
  }
ll tm=tl+tr>>1;
return (getr(l, r, 2*v, tl, tm, num)+getr(l, r, 2*v+1, tm+1, tr, num))%mod;
}

ll getl (ll l, ll r, ll v, ll tl, ll tr, ll num)
{
if (r<tl||tr<l)
  return 0;
if (l<=tl&&tr<=r)
  {
  ll ret=lt[v];
  ret+=((t[v]%mod)*(x[tl]-x[num]-tl+num));
  ret%=mod;
  return ret;
  }
ll tm=tl+tr>>1;
return (getl(l, r, 2*v, tl, tm, num)+getl(l, r, 2*v+1, tm+1, tr, num))%mod;
}

ll sum(ll l, ll r, ll v, ll tl, ll tr)
{
if (r<tl||tr<l)
  return 0;
if (l<=tl&&tr<=r)
  return t[v];
ll tm=tl+tr>>1;
return sum(l, r, 2*v, tl, tm)+sum(l, r, 2*v+1, tm+1, tr);
}

ll found(ll a, ll b)
{
ll l=a, r=b+1;
ll locs=sum(a, b, 1, 0, s-1);
ll tol=0;
while (l+1!=r)
  {
  ll mi=l+r>>1;
  ll ls=tol+sum(l, mi-1, 1, 0, s-1);
  if (2*ls<=locs)
    l=mi, tol=ls;
  else
    r=mi;
  }
return l;
}

void get(ll l, ll r, ll v, ll tl, ll tr)
{
//cout<<"Get "<<tl<<' '<<tr<<endl;
if (r<tl||tr<l)
  return;
if (l<=tl&&tr<=r)
  {
  seg.push_back({tl, tr, t[v]});
  return;
  }
ll tm=tr+tl>>1;
get(l, r, 2*v, tl, tm);
get(l, r, 2*v+1, tm+1, tr);
}

ll ver(ll l, ll r, ll v, ll tl, ll tr)
{
if (l==tl&&r==tr)
  return v;
ll tm=tl+tr>>1;
if (tm>=r)
  return ver(l, r, 2*v, tl, tm);
else
  return ver(l, r, 2*v+1, tm+1, tr);
}

ll gran (ll v, ll l, ll r, ll want)
{
if (l==r)
  return l;
if (t[v]==want)
  return r+1;
ll tm=l+r>>1;
if (t[2*v]>want)
  return gran(2*v, l, tm, want);
return gran(2*v+1, tm+1, r, want-t[2*v]);
}

ll found_new(ll a, ll b)
{
ll locs=sum(a, b, 1, 0, s-1);
seg.clear();
get(a, b, 1, 0, s-1);
 /*
cout<<"Segments"<<endl;
for (auto i:seg)
  cout<<i.l<<' '<<i.r<<' '<<i.v<<endl;
// */
vector <ll> pr;
pr.push_back(seg[0].v);
for (ll i=1; i<seg.size(); i++)
  pr.push_back(pr.back()+seg[i].v);
j=0;
while (pr[j]*2<locs)
  j++;
if (pr[j]*2==locs)
  return seg[j].r+1;
//j++;
ll l=seg[j].l;
ll r=seg[j].r;
ll want=locs/2;
if (j!=0)
  want-=pr[j-1];
ll v=ver(l, r, 1, 0, s-1);
//cout<<"Split in "<<l<<' '<<r<<' '<<v<<endl;
return gran(v, l, r, want);
}

int main()
{
//viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>q;
x.resize(n);
w.resize(n);
for (auto &i:x)
  cin>>i;
for (auto &i:w)
  cin>>i;
s=1;
while (s<n)
  s*=2;
for (i=0; i<n; i++)
  change(1, 0, s-1, i, w[i]);

if (viv)
  {
  for (i=1; i<n+s; i++)
    cout<<t[i]<<' ';
  cout<<endl;
  for (i=1; i<n+s; i++)
    cout<<lt[i]<<' ';
  cout<<endl;
  for (i=1; i<n+s; i++)
    cout<<rt[i]<<' ';
  cout<<endl;
  }

for (i=0; i<q; i++)
  {
  ll a,b;
  cin>>a>>b;
  if (a<0)
    {
    a=-a;
    a--;
    change(1, 0, s-1, a, b-w[a]);
    w[a]=b;
    }
  else
    {
    a--; b--;
    ll mi=found_new(a, b);
//    ll mi_long=found(a, b);
//    if (mi!=mi_long)
//      cout<<"Wrong!!! "<<mi<<' '<<mi_long<<endl;
    ll lans=0;
    lans+=getr(a, mi-1, 1, 0, s-1, mi);
    lans+=getl(mi+1, b, 1, 0, s-1, mi);
    lans%=mod;
    lans+=mod;
    lans%=mod;
    cout<<lans<<'\n';
    }
  }



    return 0;
}
/*
5 23
1 2 6 7 10
1 1 1 1 2
1 1
1 5
1 3
3 5
-3 5
-1 10
1 4
2 5

1 1
1 2
1 3
1 4
1 5
2 2
2 3
2 4
2 5
3 3
3 4
3 5
4 4
4 5
5 5

*/