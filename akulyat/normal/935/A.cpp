#include <iostream>

using namespace std;

int main()
{
//   cout << "Hello world!" << endl;
long n,ans=0;
cin>>n;
for (long i=1; i<n; i++)
  {
  if ((n-i)%i==0)
    ans++;
  }
cout<<ans;



    return 0;
}