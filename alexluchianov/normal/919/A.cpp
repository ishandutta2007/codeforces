#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int n , m;
  double sum = 0;
  double smin = 1000000000;
  cin>>n>>m;
  for(int i = 1 ; i <= n ;i++){
    int a , b;
    cin>>a>>b;
    double val = 1.0 * a / b;
    if(val < smin){
      smin = val;
    }
  }
  cout<<setprecision(8)<<fixed<<smin * m;
  return 0;
}