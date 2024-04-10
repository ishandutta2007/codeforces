
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
int n,i,a;
cin>>n;
for (i=0; i<n; i++){
  cin>>a;
  while (a%7!=0){
    a=a-3;
    }
  if (a>=0){
    cout<<"YES"<<endl;
    }
  else{
    cout<<"NO"<<endl;
    }

  }

    return 0;
}