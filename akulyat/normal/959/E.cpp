#include <iostream>

using namespace std;

int main()
{
 //   cout << "Hello world!" << endl;
long long ans=0, k=1, i,n,kol=0;
cin>>n;
k=1;
while (n>1)
 {
   ans+=(n/2)*k;
   k*=2;
   n=(n+1)/2;
   
 }
cout<<ans;
 return 0;
}