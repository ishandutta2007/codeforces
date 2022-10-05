#include <bits/stdc++.h>

using namespace std;

long long n,i;
long long n1,k;
vector <long long> fac,m,kol;



int main()
{
fac.push_back(1);
for (i=1; i<20; i++)
  fac.push_back(fac.back()*i);
for (i=0; i<10; i++)
  m.push_back(0);

cin>>n;
n1=n;
while (n1>0)
  {
  long long z=n1%10;
  m[z]++;
  k++;
  n1/=10;
  }

bool work=true;


for (i=0; i<10; i++)
  if (m[i]>0)
    kol.push_back(1);
  else
    kol.push_back(0);

long long raz=0;
long long ans=0;
while (work)
  {
  long long sum=0;
  for (i=0; i<10; i++)
    sum+=kol[i];
  long long lans=fac[sum];
  for (i=0; i<10; i++)
    lans/=fac[kol[i]];
  if (kol[0]>0)
    {
    long long sum2=0;
    sum2+=kol[0]-1;
    for (i=1; i<10; i++)
      sum2+=kol[i];
    long long lans2=fac[sum2];
    lans2/=fac[kol[0]-1];
    for (i=1; i<10; i++)
      lans2/=fac[kol[i]];
    lans-=lans2;
    }
  ans+=lans;
  /*
  cout<<raz<<endl;
  for (i=0; i<10; i++)
    cout<<kol[i]<<' ';
  cout<<endl;
  cout<<"here is "<<lans<<endl;
  raz++;
//  */


  kol[9]++;
  for (i=9; i>0; i--)
    {
    if (kol[i]>m[i])
      {
      kol[i]=min((long long)1, m[i]);
      kol[i-1]++;
      }
    }
  if (kol[0]>m[0])
    work=false;
  }

cout<<ans;



    return 0;
}