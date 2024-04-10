#include <iostream>
#include <cmath>

using namespace std;

/*
double const eps = 0.0001;


double binarysearch(double x , double y ){
  double val = 0;
  for(double jump = 33 ;eps < jump ;jump /= 2){
    val += jump;
    if(pow(x , val) < y){
      continue;
    } else
      val -= jump;
  }
  return val;
}
*/
int main()
{
  double x , y;
  cin >> x >> y;
  if(x == y || (x == 2 && y == 4) || (x == 4 && y == 2))
    cout << "=";
  else if(log(x) / x > log(y) / y){
    cout << ">";
  } else
    cout << "<";

  return 0;
}