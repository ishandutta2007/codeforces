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


ll n,i,j, a, b, d;
vector <ll> m;
bool viv=false;

bool ins(ll a, ll l, ll r)
{
if (a<l||a>r)
  return false;
return true;
}

void solve()
{
cin>>a>>b>>d;
vector <ll> ans;
ans.push_back(a);
ll sum=a;
while (ans.back()<b)
  {
  ll l=sum+1;
  ll r=sum+d;
                if (viv)
                  cout<<"Have "<<l<<' '<<r<<endl;
  while (l!=r)
    {
    ll mid=l+r>>1;
    ll suml=sum;
    ll sumr=sum;
    ll ladd=l;
    ll radd=mid;
    while (radd<b)
      suml+=ladd, sumr+=radd, ladd=suml+1, radd=sumr+d;
    if (ladd<=b)
      r=mid;
    else
      l=mid+1;
                  if (viv)
                    cout<<"Let it be "<<l<<' '<<r<<endl;
    }
  ans.push_back(l);
  sum+=l;
                if (viv)
                  cout<<"Add "<<l<<endl;
  }
if (ans.back()==b)
  {
  cout<<ans.size()<<' ';
  for (auto i:ans)
    cout<<i<<' ';
  cout<<endl;
  return;
  }
cout<<-1<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll t;
cin>>t;
while (t)
  solve(), t--;

    return 0;
}