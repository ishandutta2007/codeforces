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


ll n,m,i,j,b,w;
ll a1,b1,c1,d1;
ll a2,b2,c2,d2;
ll ans=0;
bool viv=false;

void change_w(ll a, ll b, ll c, ll d, ll &w, ll &bl)
{
ll s=(c-a)*(d-b);
ll kol=s/2;
if (((a+b)&1)&&(s&1))
  kol++;
if (viv)
  cout<<w<<' '<<bl<<endl;
if (viv)
  cout<<"AAA1 "<<kol<<endl;
w+=kol;
bl-=kol;
if (viv)
  cout<<w<<' '<<bl<<endl;
}

void change_b(ll a, ll b, ll c, ll d, ll &w, ll &bl)
{
ll s=(c-a)*(d-b);
ll kol=s/2;
if (!((a+b)&1)&&(s&1))
  kol++;
if (viv)
  cout<<"AAA2 "<<kol<<endl;
bl+=kol;
w-=kol;
}

void change_b2(ll a, ll b, ll c, ll d, ll &w, ll &bl)
{
ll s=(c-a)*(d-b);
ll kol=s/2;
if (((a+b)&1)&&(s&1))
  kol++;
if (viv)
  cout<<"AAA3 "<<kol<<endl;
bl+=kol;
w-=kol;
}

void solve()
{
cin>>n>>m;
cin>>a1>>b1>>c1>>d1; c1++, d1++;
cin>>a2>>b2>>c2>>d2; c2++, d2++;
b=n*m/2;
w=n*m-b;
ans=0;
if (viv)
  cout<<w<<' '<<b<<' ';
change_w(a1, b1, c1, d1, w, b);
if (viv)
  cout<<"___ "<<w<<' '<<b<<endl;
change_b(a2, b2, c2, d2, w, b);
if (viv)
  cout<<"___ "<<w<<' '<<b<<endl;
a2=max(a2, a1);
b2=max(b2, b1);
c2=min(c2, c1);
d2=min(d2, d1);
if (viv)
  cout<<"Common "<<a2<<' '<<b2<<' '<<c2<<' '<<d2<<endl;
if (c2>a2&&d2>b2)
  change_b2(a2, b2, c2, d2, w, b);
if (viv)
  cout<<"Answer         ";
cout<<w<<' '<<b<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t)
  {
  solve();
  t--;
  }

    return 0;
}