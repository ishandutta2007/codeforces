#include <bits/stdc++.h>

using namespace std;

long long i,n,q;
vector <long long> m,st;
map <long long, long long> kol;

void solve(long long x)
{
long long ans=0;
long long i;
for (i=34; i>=0; i--)
  {
  long long z=st[i];
  long long have=kol[z];
  long long want=x/z;
//  cout<<x<<' '<<z<<' '<<have<<' '<<want<<' '<<endl;
  want=min(want, have);
  ans+=want;
  x-=want*z;
  }
if (x==0)
  cout<<ans<<endl;
else
  cout<<-1<<endl;
}

int main()
{
cin>>n>>q;
for (i=0; i<35; i++)
  {
  long long z=1ll<<i;
  st.push_back(z);
  kol[z]=0;
  }
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  kol[a]++;
  m.push_back(a);
  }
for (i=0; i<q; i++)
  {
  long long a;
  cin>>a;
  solve(a);
  }




    return 0;
}