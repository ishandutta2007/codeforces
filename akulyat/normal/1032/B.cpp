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


ll n,i,j;
pll ans;
vector <ll> m;
bool viv=false;
string s;

void offer(ll y, ll x)
{
if (y>5||x>20)
  return;
if (ans.F>y||(ans.F==y&&ans.S>x))
ans={y, x};
}

void use(ll l)
{
for (ll st=1; st<6; st++)
  if (l%st==0)
    offer(st, l/st);
}

void work ()
{
cout<<ans.F<<' '<<ans.S<<endl;
ll z=ans.F*ans.S;
z-=n;
ll bef=0;
while (z)
  {
  string a=s.substr(0, bef)+'*'+s.substr(bef, s.size()-bef);
  s=a;
  bef+=ans.S;
  z--;
  }
for (i=0; i<ans.F; i++)
  {
  for (j=0; j<ans.S; j++)
    cout<<s[i*ans.S+j];
  cout<<endl;
  }

}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s;
n=s.size();
ans={inf, inf};
for (ll l=n; l<n+100; l++)
  use(l);
work();


    return 0;
}
//qwertqwertqwertqwertqwertqwertqwertqwertqwertqertqrtqwtqwetqwertqewrtqertqewrtqretqwertqwertqert