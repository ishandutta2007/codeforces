#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long n,i,a[1000],b[1000];
cin>>n;
for (i=0; i<n; i++)
  {
  char cc;
  cin>>cc;
  a[i]=cc;
  if (i>0)
    if (((cc=='a')||(cc=='o')||(cc=='u')||(cc=='i')||(cc=='e')||(cc=='y'))
    &&((a[i-1]=='a')||(a[i-1]=='o')||(a[i-1]=='u')||(a[i-1]=='e')||(a[i-1]=='i')||(a[i-1]=='y')))
      b[i]=23;
  }
string an;
an="";
for (i=0; i<n; i++)
  if (b[i]!=23)
    an+=a[i];
cout<<an;




    return 0;
}