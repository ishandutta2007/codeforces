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


ll n,i,j, ans, gans;
vector <ll> m;
bool viv=false;

ll star()
{
ll res=0;
for (auto i:m)
  res+=abs(i-1);
return res;
}

void ch(ll pl)
{
ans-=abs(m[pl]-1);
ans+=abs(m[pl]+1);
ans-=abs(m[pl-1]-1);
ans+=abs(m[pl-1]+1);
gans=min(gans, ans);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
sort(m.begin(), m.end());
ans=star();
gans=ans;
for (ll i=1; i<n; i+=2)
  ch(i);
cout<<gans<<endl;


  
    return 0;
}