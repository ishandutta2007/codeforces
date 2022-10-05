#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;
//const long long mod=7;
long long i,j,n;
vector <long long> m,kol,f, obrf;

long long obr(long long v, long long mod)
{
long long i=0;
long long st=mod-2;
vector <long long> bin;
long long l=0;
while(st>0)
  {
  bin.push_back(st&1);
  st/=2;
  l++;
  }

vector <long long> sq;
sq.push_back(v);
for (i=1; i<l; i++)
  {
  long long s=sq.back();
  s*=s;
  s%=mod;
  sq.push_back(s);
  }

long long ans=1;
for (i=0; i<l; i++)
  if (bin[i])
    {
    ans*=sq[i];
    ans%=mod;
    }
return ans;
}


long long C (long long n, long long k)
{
if (k>n)
  return 0;

long long ans=f[n];
ans%=mod;
ans*=obrf[k];
ans%=mod;
ans*=obrf[n-k];
ans%=mod;

return ans;
}


int main()
{
f.push_back(1);
obrf.push_back(1);
for (i=1; i<=10000; i++)
  {
  long long v=f.back()*i;
  v%=mod;
  f.push_back(v);
  obrf.push_back(obr(v, mod));
  }


cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }

reverse(m.begin(), m.end());

for (i=0; i<n; i++)
  {
  kol.push_back(0);
  long long v=m[i];
  if (v>0)
    kol[i]=C(i, v);
  if (v>0)
    {
    for (j=0; j<i; j++)
      {
      kol[i]+=((kol[j]*C(i-j-1, v))%mod);
      kol[i]%=mod;
      }
    }
  }
/*
for (i=0; i<n; i++)
  cout<<kol[i]<<' ';
cout<<endl;
*/
long long ans=0;
for (i=0; i<n; i++)
  {
  ans+=kol[i];
  ans%=mod;
  }

cout<<ans;



    return 0;
}