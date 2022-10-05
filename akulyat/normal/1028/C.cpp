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

struct vertex
{
ll x1,y1,x2,y2;
};

ll n,i,j;
vector <vertex> m;
bool viv=false;
vector <ll> xl,xr,yd,yu;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  m.push_back({a, b, c, d});
  xl.push_back(a);
  xr.push_back(c);
  yd.push_back(b);
  yu.push_back(d);
  }

sort (xl.rbegin(), xl.rend());
sort (xr.begin(), xr.end());
sort (yd.rbegin(), yd.rend());
sort (yu.begin(), yu.end());

/*
for (auto i:xl)
  cout<<i<<' ';
cout<<endl;
for (auto i:yd)
  cout<<i<<' ';
cout<<endl;
for (auto i:xr)
  cout<<i<<' ';
cout<<endl;
for (auto i:yu)
  cout<<i<<' ';
cout<<endl;
*/



for (auto i:m)
  {
  ll a,b,c,d;
  a=xl[0];
  b=yd[0];
  c=xr[0];
  d=yu[0];
  if (i.x1==a)
    a=xl[1];
  if (i.y1==b)
    b=yd[1];
  if (i.x2==c)
    c=xr[1];
  if (i.y2==d)
    d=yu[1];
  if (a<=c&&b<=d)
    {
    cout<<a<<' '<<b<<endl;
    return 0;
    }
  }











    return 0;
}