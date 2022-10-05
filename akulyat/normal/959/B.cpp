#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k,l;
vector <ll> m,pl,pr;
vector <string> ss;
bool viv=false;
map <string, ll> st;

int main()
{
cin>>n>>k>>l;
for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  ss.push_back(s);
  pl.push_back(0);
  st[s]=i;
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
for (i=0; i<k; i++)
  {
  ll l;
  cin>>l;
  ll mini=inf;
  for (j=0; j<l; j++)
    {
    ll num;
    cin>>num;
    num--;
//    nab[i].push_back(num);
    mini=min(mini, m[num]);
    pl[num]=i;
    }
  pr.push_back(mini);
  }

ll ans=0;
for (i=0; i<l; i++)
  {
  string s;
  cin>>s;
  ll num=st[s];
  ans+=pr[pl[num]];
  }
cout<<ans<<endl;


    return 0;
}
/*
5 4 4
i loser am the second
100 1 1 5 10
1 1
1 3
2 2 5
1 4
i am the second


*/