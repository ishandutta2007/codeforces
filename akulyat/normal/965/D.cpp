#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long inf=kk*kk*kk+7;
long long n,l,i,j;
set <long long> s;
vector <long long> m,ost;


int main()
{
cin>>n>>l;
m.push_back(inf);
ost.push_back(0);
for (i=0; i<n-1; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  ost.push_back(a);
//  if (a>0)
//    s.insert(-i-1);
  }
m.push_back(inf);
ost.push_back(inf);
//s.insert(-n);

/*
for (auto i:m)
    cout<<i<<' ';
cout<<endl;
for (auto i:ost)
    cout<<i<<' ';
cout<<endl;
for (auto i:s)
    cout<<i<<' ';
cout<<endl;
*/

vector <long long> add;
for (i=0; i<l; i++)
  if (ost[i]>0)
    add.push_back(i);

for (i=0; i<n; i++)
  {
  if (i+l<=n)
    if (ost[i+l]>0)
      add.push_back(i+l);
  m[i]-=ost[i];
  //long long z=-(*lower_bound(s.begin(), s.end(), -(i+l)));
  long long z=-1;
  if (add.size()>0)
    z=add.back();

  while (m[i]>0&&z>i)
    {
    long long a=min(m[i], ost[z]);
//    cout<<"Oh, i put "<<a<<" from "<<i<<" to "<<z<<'{'<<m[i]<<' '<<ost[z]<<'}'<<endl;
    m[i]-=a;
    ost[z]-=a;
    if (ost[z]==0)
      add.pop_back();
    z=-1;
    if (add.size()>0)
      z=add.back();

/*
    for (auto j:s)
      cout<<j<<' ';
    cout<<endl;
    cin>>n;
*/
    }
  }


cout<<m.back()-ost.back();





    return 0;
}