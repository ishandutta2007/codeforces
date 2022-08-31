#include <iostream>
#include <math.h>
#include<iomanip>
#include<cmath>
#define in long long
#define cout cout<<fixed<<setprecision(0)
using namespace std;

int main()
{
  int n;
  cin>>n;
  in* x = new in[n];
  in mid = n/2;

  for(int i = 0; i<n;i++){
    cin>>x[i];

  }
    in maximum=x[n-1];
  in minimum=x[0];
  for(int i = 0; i<n; i++){
    if(i!=n-1&&i!=0){
    cout<<min(abs(x[i]-x[i+1]), abs(x[i]-x[i-1]));
    cout<<" ";
    cout<<max(abs(x[i]-maximum),abs(x[i]-minimum));
    cout<<endl;
  }
  else if(i==0){
    cout<<abs(x[i]-x[i+1])<< " ";
    cout<<abs(x[i]-maximum);
    cout<<endl;

  }
  else{
    cout<<abs(x[i]-x[i-1])<< " ";
    cout<<abs(x[i]-minimum);
  }
  }

return 0;
}