#include <bits/stdc++.h>

using namespace std;


long n,k,i,j,k1,k2;
int main()
{
cin>>n>>k;
if (k%2==0)
  {
  k1=k/2;
  k2=k1;
  }
if (k%2==0)
{
cout<<"YES"<<endl;
for (i=0; i<n; i++)
  cout<<'.';
cout<<endl;
cout<<'.';
for (i=1; i<n-1; i++)
  if (k1>0)
    {
    cout<<'#';
    k1--;
    }
  else
    cout<<'.';
cout<<'.';
cout<<endl;
cout<<'.';
for (i=1; i<n-1; i++)
  if (k2>0)
    {
    cout<<'#';
    k2--;
    }
  else
    cout<<'.';
cout<<'.';
cout<<endl;
for (i=0; i<n; i++)
  cout<<'.';
return 0;
}

cout<<"YES"<<endl;
if (k>n-2)
  {
  k1=(n-2)/2+1;
  k2=((n-2)-(k-(n-2)))/2+1;
  }
else
  {
  k1=(k/2)+1;
  k2=100000;
  }

//cout<<"OK "<<k1<<' '<<k2<<endl;

for (i=0; i<n; i++)
  cout<<'.';
cout<<endl;

for (i=0; i<n; i++)
  if ( abs(i-(n/2))<k1)
    cout<<'#';
  else
    cout<<'.';
cout<<endl;
cout<<'.';
for (i=1; i<n-1; i++)
  if (abs(i-(n/2))<k2)
    cout<<'.';
  else
    cout<<'#';
cout<<'.';
cout<<endl;

for (i=0; i<n; i++)
  cout<<'.';
cout<<endl;


    return 0;
}