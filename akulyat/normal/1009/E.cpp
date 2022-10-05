#include <bits/stdc++.h>

using namespace std;

const long long mod=998244353;
const long long ml=1000*1000;
const long long kk=1000;
vector <long long> m,a,b,c,d,e;
long long n,i;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
a.push_back(2);
a.push_back(5);
long long z=1;
for (i=2; i<ml+kk; i++)
  {
  a.push_back(a.back()*2+z);
  a.back()%=mod;
  z*=2;
  z%=mod;
  a.back()%=mod;
  }
b.push_back(2);
for (i=1; i<ml+kk-10; i++)
  {
  b.push_back(b.back()+a[i-1]);
  b.back()%=mod;
  }
c.push_back(1);
for (i=1; i<ml+kk-10-10; i++)
  {
  c.push_back(c.back()+b[i-1]);
  c.back()%=mod;
  }
d.push_back(1);
for (i=1; i<ml+kk-10-10-10; i++)
  {
  d.push_back(d.back()+c[i-1]);
  d.back()%=mod;
  }
e.push_back(0);
for (i=1; i<ml+kk-10-10-10-10; i++)
  {
  e.push_back(e.back()+d[i-1]);
  e.back()%=mod;
  }




for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }
reverse(m.begin(), m.end());
long long ans=0;
for (i=0; i<n; i++)
  {
  ans+=(m[i]*e[i+1])%mod;
  ans%=mod;
  }

cout<<ans<<endl;
/*
for (i=0; i<5; i++)
    cout<<ar[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
    cout<<m[i]<<' ';
cout<<endl;
*/
    return 0;
}