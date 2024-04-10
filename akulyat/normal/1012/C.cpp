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
vector <ll> m;
long long ans[5*kk+3][3*kk+3];
long long best[5*kk+3][3*kk+3];
bool viv=false;


int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
m.push_back(-1);
for (i=0; i<n; i++)
  for (j=1; j<(n/2)+4; j++)
    ans[i][j]=inf;
for (i=0; i<n; i++)
  for (j=1; j<(n/2)+4; j++)
    best[i][j]=inf;

vector <ll> ot;
for (i=0; i<=n; i++)
  ot.push_back(inf);
for (i=0; i<n; i++)
  {
// /*
  ans[i][0]=max(0ll, m[i+1]-m[i]+1);
//  best[i][0]=ans[i][0];
  if (i>0)
    {
    ans[i][0]+=max(0ll, m[i-1]-m[i]+1);
//    best[i][0]=ans[i][0];
//    best[i][0]=min(best[i][0], best[i-1][0]);
    }
// */
//  cout<<"Have "<<0<<" using "<<i+1<<" = "<<ans[i][0]<<" ("<<best[i][0]<<")"<<endl;
  for (j=1; j<=(i/2)+1; j++)
    {
    ans[i][j]=max(0ll, m[i+1]-m[i]+1);
    ll last=0;
    if (i>0)
      last=max(0ll, m[i-1]-m[i]+1);
    ans[i][j]+=last;
    if (i>1)
      ans[i][j]+=min(best[i-2][j-1], ans[i-2][j-1]-max(0ll, m[i-1]-m[i-2]+1)+max(0ll, m[i]-m[i-2]));
    best[i][j]=ans[i][j];
    if (i>0)
      best[i][j]=min(best[i][j], best[i-1][j]);
//    cout<<"Have "<<j<<" using "<<i+1<<" = "<<ans[i][j]<<" ("<<best[i][j]<<")"<<endl;
    ot[j]=min(ot[j], (long long)ans[i][j]);
    }
  }
for (i=1; i<=n; i++)
  if (ot[i]!=inf)
    cout<<ot[i]<<' ';




    return 0;
}

/*
21
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1


*/