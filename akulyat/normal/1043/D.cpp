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


ll n,i,j,ch,k;
vector <ll> h,con;
vector <ll> m[20];
bool viv=false;
string s[10];
ll pl[13][130*kk];

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
if (k==1)
  {
  cout<<n*(n+1)/2;
  return  0;
  }
for (i=0; i<k; i++)
  {
  for (j=0; j<n; j++)
    {
    ll a;
    cin>>a;
    a--;
    pl[i][a]=j;
    m[i].push_back(a);
    }
  m[i].push_back(mod+i);
  }
vector <ll> will(n, true);
ll ans=0;
for (ll u=0; u<n; u++)
  if (will[m[0][u]])
    {
    ll i=m[0][u];
    ll z=1;
    vector <ll> b;
    for (j=0; j<k; j++)
      b.push_back(pl[j][i]);
    bool w=true;
    while (w)
      {
      ll sov=0;
      for (ll u=1; u<k; u++)
        if (m[u][b[u]+z]==m[0][b[0]+z])
          sov++;
      w=false;
      if (sov==k-1)
        {
        if (m[0][b[0]+z]<n)
         will[m[0][b[0]+z]]=false;
        w=true;
        z++;
        }
//      cout<<i<<' '<<z<<' '<<w<<endl;
      }
 //   cout<<z<<endl;
    ans+=z*(z+1)/2;
    }
cout<<ans;




    return 0;
}