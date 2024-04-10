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
const int b=26;

ll n,i,j;
vector <ll> m,og;
bool viv=false;
string s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s;
og.resize(b);
for (auto &i:og)
  cin>>i;

vector <ll> ans,shortest;
ans.push_back(1);
shortest.push_back(0);
ll mal=0;
for (i=0; i<n; i++)
  {
  ans.push_back(0);
  shortest.push_back(inf);
  j=i;
  ll mas=inf;
  while (j>=0)
    {
    mas=min(mas, og[s[j]-'a']);
    j--;
    if (mas>=i-j)
      {
      ans[i+1]+=ans[j+1];
      ans[i+1]%=mod;
      mal=max(mal, i-j);
      shortest[i+1]=min(shortest[i+1], shortest[j+1]+1);
      }
    }
  }
cout<<ans[n]<<endl;
cout<<mal<<endl;
cout<<shortest[n]<<endl;

/*
for (i=0; i<=n; i++)
  cout<<ans[i]<<' ';
cout<<endl;
for (i=0; i<=n; i++)
  cout<<shortest[i]<<' ';
cout<<endl;
// */

    return 0;
}