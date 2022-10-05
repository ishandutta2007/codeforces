#include <bits/stdc++.h>

using namespace std;

vector <long> m,m2;
long n,i,j;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a);}

if (n<=2)
  {
  cout<<0;
  return 0;
  }


//sort(m.begin(), m.end());

long best=2*n;

for (i=0; i<9; i++)
  {
  long kol=2;
  m2.clear();
  for (long j=0; j<n; j++)
    m2.push_back(m[j]);

  m2[0]+=((i%3)-1);
  m2[1]+=(((i/3)%3)-1);
  if (m2[0]==m[0])
    kol--;
  if (m2[1]==m[1])
    kol--;
  long start=m2[0];
  long shag=m2[1]-m2[0];
  for (long j=0; j<n; j++)
    {
    if (start!=m2[j])
      kol++;
    if (abs(m2[j]-start)>1)
      {
      kol+=2*n;
      break;
      }
    start+=shag;
    }
  best=min(best, kol);
//  cout<<"Ok, "<<kol<<" if we use "<<i<<endl;
  }

if (best<=n)
  {
  cout<<best;
  return 0;
  }

cout<<-1;
    return 0;
}