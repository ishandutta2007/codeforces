#include <iostream>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long n,a,b;
cin>>n>>a>>b; a--; b--;
long r=0;
while (a!=b)
    {
    r++;
    a/=2; b/=2;
    }
long k=1; long kol=0;
while (k!=n)
{
  k*=2;
  kol++;
}

if (r==kol)
  cout<<"Final!";
  else cout<<r;

    return 0;
}