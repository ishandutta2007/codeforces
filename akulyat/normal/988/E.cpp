#include <bits/stdc++.h>

using namespace std;

string s;
long long n,i,j;
vector <long long> m;
long long ans=-1;


long long use(long long a, long long b)
{
vector <long long> m1=m;
//cout<<"Try "<<a<<' '<<b<<endl;
long long i;
long long kol=0;
long long posa=n;
for (i=n-1; i>=0; i--)
  if (m1[i]==a)
    posa=i;

if (posa==n)
  {
  //cout<<"Without "<<a<<endl;
  return 1000;
  }
while (posa>0)
  {
  swap(m1[posa], m1[posa-1]);
  posa--;
  kol++;
  }

long long posb=n;
for (i=n-1; i>=1; i--)
  if (m1[i]==b)
    posb=i;


if (posb==n)
  {
  //cout<<"Without "<<b<<endl;
  return 1000;
  }
while (posb>1)
  {
  swap(m1[posb], m1[posb-1]);
  posb--;
  kol++;
  }

long j2=n-1;
while (m1[j2]==0)
  {
  kol++;
  j2--;
  }

return kol;
}

int main()
{
cin>>s;
n=s.size();
for (i=0; i<n; i++)
  m.push_back((long long)(s[i]-'0'));
reverse(m.begin(), m.end());


ans=1000;
ans=min(use(0, 0), ans);
ans=min(use(5, 2), ans);
ans=min(use(0, 5), ans);
ans=min(use(5, 7), ans);
if (ans==1000)
  ans=-1;
cout<<ans;


    return 0;
}