#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;

long long x,k,a,ans;

long long pp(long long x)
{
long long i=0;

vector <long long> m,st;
long long x1=x;
long long res=1;

while (x1>0)
  {
  m.push_back(x1&1);
  x1/=2;
  }

st.push_back(2);

for (i=1; i<100; i++)
  {
  long long v=st.back();
  v=v*v;
  v%=mod;
  st.push_back(v);
  }
for (i=0; i<m.size(); i++)
  {
  if (m[i])
    res*=st[i];
  res%=mod;
  }

return res;
}

int main()
{
cin>>x>>k;
if (x==0)
  k=0;
x%=mod;
a=pp(k);

ans=((2*x*a)%mod-a+1)%mod;
while (ans<0)
  ans+=mod;


cout<<ans<<endl;

    return 0;
}