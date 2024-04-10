#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long inf=kk*kk*kk;
long long n,k,z,i,j;
bool r[4000];
long long um[4000];
vector <long long> ans;

int main()
{
cin>>n>>k>>z;
for (i=0; i<k; i++)
  {
  long a,b;
  cin>>a>>b;
  for (long j=a+1; j<=b; j++)
    r[j]=true;
  }
for (i=0; i<=n; i++)
  um[i]=inf;
for (i=0; i<z; i++)
  {
  long long a,b;
  cin>>a>>b;
  um[a]=min(um[a], b);
  }

ans.push_back(0);
for (i=1; i<=n; i++)
  {
  if (!r[i])
    ans.push_back(ans.back());
  else
    ans.push_back(inf);
//  cout<<"Ok "<<ans.back()<<endl;
  for (j=0; j<i; j++)
    {
    if (um[j]!=inf)
      ans.back()=min(ans.back(), ans[j]+um[j]*(i-j));
    }
//  cout<<"Ok "<<ans.back()<<endl;
  }

if (ans[n]==inf)
  ans[n]=-1;

cout<<ans.back();

    return 0;
}