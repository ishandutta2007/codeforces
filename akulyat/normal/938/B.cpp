#include <iostream>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long i,n,max=0;
cin>>n;
for (i=0; i<n; i++)
  {
  long p,tim;
  cin>>p;
  tim=min(1000000-p, p-1);
  if (tim>max)
    max=tim;
  }


cout<<max;
    return 0;
}