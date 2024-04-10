#include <iostream>
#include<math.h>
using namespace std;

int main()
{
long long n,k;
cin>>n>>k;
long long j = 0;
long long z = 0;
if(n%2!=0){
    z = (n/2)+1;
}
else{
    z=(n/2);
}
if(k<=z){

  cout<<k*2-1;

}
else{
   cout<<((k - (z)) * 2);

}
}