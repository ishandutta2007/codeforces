#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
long long i,n,d,k,nex;
vector <long long> m,reb;
long long sos[500*kk];


void add(long long v, long long l)
{
while (nex<n&&l<d&&sos[v]<k)
  {
  reb.push_back(v);
  reb.push_back(nex);
  sos[v]++;
  sos[nex]++;
  long long s=nex;
  nex++;
//  cout<<"Go from "<<v<<" to "<<nex<<endl;
  add(s, l+1);
  }

}


void solve1()
{
if (d!=1)
  cout<<"NO";
else
  cout<<"YES";
exit(0);
}

void solve2()
{
if (d!=2)
  cout<<"NO";
else
  {
  cout<<"YES"<<endl;
  cout<<"1 2"<<endl;
  }
exit(0);
}


int main()
{
cin>>n>>d>>k;
d++;
if (n==1)
  solve1();
if (n==2)
  solve2();

if (d>n)
  {
  cout<<"NO"<<endl;
  return 0;
  }

if (k==1)
  {
  cout<<"NO"<<endl;
  return 0;
  }

for (i=0; i<d-1; i++)
  {
  reb.push_back(i);
  reb.push_back(i+1);
  sos[i]++;
  sos[i+1]++;
  }

nex=d;
for (i=0; i<d; i++)
  add(i, max(i+1, d-i));

if (nex!=n)
  {
  cout<<"NO";
  return 0;
  }

cout<<"YES"<<endl;
for (i=0; i<reb.size(); i+=2)
  {
  cout<<reb[i]+1<<' ';
  cout<<reb[i+1]+1<<endl;
  }



    return 0;
}