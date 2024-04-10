#include <bits/stdc++.h>

using namespace std;

long long i,n;
set <long long> s;
vector <long long> m,ans,l,r,kol;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ans.push_back(0);
  long long a,b;
  cin>>a>>b;
  b++;
  s.insert(a);
  s.insert(b);
  l.push_back(a);
  r.push_back(b);
  }

for (auto i:s)
  m.push_back(i);

sort(m.begin(), m.end());
sort(l.begin(), l.end());
sort(r.begin(), r.end());

long long k=m.size();


long long j1=0;
long long j2=0;

//cout<<"Working:"<<endl;
for (i=0; i<k; i++)
  {
  long long v=m[i];
  kol.push_back(0);
  while (j1<n&&l[j1]<v)
    j1++;
  long long rj1=j1;
  while (j1<n&&l[j1]==v)
    j1++;
  kol[i]+=(j1-rj1);
//  cout<<rj1<<' '<<j1<<endl;
  while (j2<n&&r[j2]<v)
    j2++;
  long long rj2=j2;
  while (j2<n&&r[j2]==v)
    j2++;
  kol[i]-=(j2-rj2);
//  cout<<rj2<<' '<<j2<<endl;
  }
/*
for (i=0; i<k; i++)
  cout<<m[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<l[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<r[i]<<' ';
cout<<endl;
for (i=0; i<k; i++)
  cout<<kol[i]<<' ';
cout<<endl;
*/


long long h=0;
for (i=0; i<k-1; i++)
  {
  h+=kol[i];
  long long lh=h;
  lh-=1;
  if (lh!=-1)
    ans[lh]+=m[i+1]-m[i];
  }

for (i=0; i<n; i++)
  cout<<ans[i]<<' ';

    return 0;
}