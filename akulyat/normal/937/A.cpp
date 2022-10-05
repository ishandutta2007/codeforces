#include <iostream>

using namespace std;

int main()
{
 //   cout << "Hello world!" << endl;
long a,b,a1,i,n,kol=0;
long nal[1000];
cin>>n;
for (i=0; i<601; i++)
{
  nal[i]=0;
}
for (i=0; i<n; i++)
{
   long a; cin>>a;
   nal[a]=1;
}
for (i=1; i<601; i++)
if (nal[i]==1)
 kol++;
 cout<<kol;


 return 0;
}