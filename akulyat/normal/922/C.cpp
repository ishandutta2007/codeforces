#include <iostream>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long long n,k;
cin>>n>>k;

for (long i=1; i<=min(k, (long long)30000000); i++)
  if (n%i!=i-1)
    {
    cout<<"No";
    return 0;
    }

cout<<"Yes";






  return 0;
}