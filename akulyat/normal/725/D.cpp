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


ll n,i,j,kol, have;
vector <pll> m;
bool viv=false;
multiset<ll> s;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  if (i!=0)
    m.push_back({a, b-a+1});
  else
    kol=a;
  }

sort(m.rbegin(), m.rend());

ll ans=n;
ll mi=1;
    {
    s.clear();
    ll have=kol;
    ll vv=0;
    ll p=0;
    while (p!=n-1&&m[p].F>have)
      {
      s.insert(m[p].S);
      p++;
      }
    ans=min(ans, p-vv+1);
//    cout<<"Place "<<p+1<<" at start"<<endl;
    while (p-vv+1>mi&&have)
      {
      ll z=*s.begin();
      if (z>have)
        have=0;
      else
        {
        vv++;
        have-=z;
        s.erase(s.begin());
        while (p!=n-1&&m[p].F>have)
          {
          s.insert(m[p].S);
          p++;
          }
        ans=min(ans, p-vv+1);
        }

      }
//    cout<<"Place "<<p-vv+1<<" at finish"<<endl;
    }

cout<<ans<<endl;



    return 0;
}