#include <iostream>

using namespace std;

int main()
{
   // cout << "Hello world!" << endl;
long k;
cin>>k;
if (k>36)
  {
  cout<<-1;
  return 0;
  }

long long ch=0;
while (k>1)
  {
  ch=ch*10+8;
  k-=2;
  }
if (k==1)
  ch=ch*10+6;
cout<<ch;

    return 0;
}