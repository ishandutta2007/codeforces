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
const ll con=1;

ll n,i,j, sum;
vector <ll> val;
bool viv=false;
vector <bitset<62>> mas;
vector <vector <ll>> have, las;

bitset <62> b_mask(ll v)
{
bitset <62> res;
for (ll i=0; i<62; i++)
  res[i]=v&1, v>>=1;
return res;
}


void read()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll lv, lm;
  cin>>lv>>lm;
  sum+=lv;
  val.push_back(lv);
  mas.push_back(b_mask(lm));
  }
if (sum<0)
  for (auto &v:val)
    v*=-1;
}

void prepare()
{
have.resize(62);
las.resize(62);
for (ll i=0; i<n; i++)
  {
  ll lasb=0;
  for (ll j=0; j<62; j++)
    if (mas[i][j])
      have[j].push_back(i), lasb=j;
  las[lasb].push_back(i);
  if (viv)
    cout<<i<<" to "<<lasb<<endl;
  }
}

bool solve(ll b)
{
ll lsum=0;
for (auto i: las[b]) 
  lsum+=val[i];
if (viv)
  cout<<b<<' '<<lsum<<endl;
if (lsum<=0)
  return false;
for (auto i:have[b])
  val[i]*=-1;
return true;
}

ll work()
{
ll res=0; 
vector <ll> v;
for (ll i=0; i<62; i++)
  v.push_back(solve(i));
reverse(v.begin(), v.end());
for (auto i:v)
  res*=2, res+=i;
return res;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
srand(time(0));
read();
prepare();
cout<<work();

    return 0;
}