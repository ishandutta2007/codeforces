#include <iostream>

using namespace std;

long n,i;
string s;
bool m[10];

int main()
{
cin>>n;
for (i=0; i<6; i++)
  m[i]=true;
getline(cin, s);
for (i=0; i<n; i++)
  {
  getline(cin, s);
  if (s[0]=='p')
    m[0]=false;
  if (s[0]=='g')
    m[1]=false;
  if (s[0]=='b')
    m[2]=false;
  if (s[0]=='o')
    m[3]=false;
  if (s[0]=='r')
    m[4]=false;
  if (s[0]=='y')
    m[5]=false;
  }

long k=0;
for (i=0; i<6; i++)
  if (m[i])
    k++;
cout<<k<<endl;

if (m[0])
  cout<<"Power"<<endl;
if (m[1])
  cout<<"Time"<<endl;
if (m[2])
  cout<<"Space"<<endl;
if (m[3])
  cout<<"Soul"<<endl;
if (m[4])
  cout<<"Reality"<<endl;
if (m[5])
  cout<<"Mind"<<endl;

    return 0;
}