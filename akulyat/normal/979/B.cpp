#include <iostream>

using namespace std;

long n,i,j;
string s[4];
long a[3][1000000];
long best[3];

int main()
{
cin>>n;
getline(cin, s[0]);
for (i=0; i<3; i++)
  getline(cin, s[i]);

long l=s[1].size();
if (s[0][l-1]==' ')
  l--;

for (j=0; j<3; j++)
  {
  for (i=0; i<l; i++)
    {
    a[j][long(s[j][i])]++;
    //cout<<long(s[j][i])<<endl;
    }
  long r=0;
  for (i=long('A'); i<=long('z'); i++)
    r=max(r, a[j][i]);
  best[j]=r;

  }


for (i=0; i<3; i++)
  if (best[i]==l&&n==1&&l!=1)
    best[i]=l-2;

for (i=0; i<3; i++)
  best[i]+=n;

for (i=0; i<3; i++)
  best[i]=min(l, best[i]);

if (best[0]>best[1]&&best[0]>best[2])
  {
  cout<<"Kuro";
  return 0;
  }
if (best[1]>best[0]&&best[1]>best[2])
  {
  cout<<"Shiro";
  return 0;
  }
if (best[2]>best[1]&&best[2]>best[0])
  {
  cout<<"Katie";
  return 0;
  }
cout<<"Draw";
    return 0;
}