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
const ll n=100;
const ll k=7;

ll i,j;
vector <ll> m;
bool viv=false;

ll int1(ll x)
{
vector <ll> a;
for (ll i=0; i<k; i++)
  a.push_back(x&1), x>>=1;

vector <ll> b;
for (ll i=0; i<a.size()-1; i++)
  b.push_back(a[i]);
for (ll i=0; i<k; i++)
  b.push_back(0);
b.push_back(a.back());
reverse(b.begin(), b.end());

ll res=0;
for (auto i:b)
  res<<=1, res+=i;
return res;
}

ll int2(ll x)
{
vector <ll> a;
for (ll i=0; i<k; i++)
  a.push_back(x&1), x>>=1;

vector <ll> b;
for (ll i=0; i<a.size()-1; i++)
  b.push_back(0);
for (ll i=0; i<k; i++)
  b.push_back(a[i]);
b.push_back(0);
reverse(b.begin(), b.end());

ll res=0;
for (auto i:b)
  res<<=1, res+=i;
return res;
}

void checker()
{
vector <ll> ans(2);

cout<<"? ";
for (ll i=0; i<n; i++)
  cout<<m[i]<<' ';
cout<<endl;
cin>>ans[0];

cout<<"? ";
for (ll i=0; i<n; i++)
  cout<<m[n+i]<<' ';
cout<<endl;
cin>>ans[1];

vector <ll> b[2];
for (ll i=0; i<14; i++)
  b[0].push_back(ans[0]&1), ans[0]>>=1;
for (ll i=0; i<14; i++)
  b[1].push_back(ans[1]&1), ans[1]>>=1;
for (ll i=6; i<13; i++)
  b[1][i]=b[0][i];

ll res=0;
for (ll i=13; i>=0; i--)
  res<<=1, res+=b[1][i];
cout<<"! "<<res<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
for (i=0; i<n; i++)
  m.push_back(int1(i));
for (i=0; i<n; i++)
  m.push_back(int2(i+1));
ll maxval=0;
for (auto i:m)
  maxval=max(maxval, i);
//cout<<maxval<<endl;

checker();









    return 0;
}