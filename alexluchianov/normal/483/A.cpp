#include <iostream>
#include <fstream>

using namespace std;
//ifstream in ("counterexample.in");
//ofstream out ("counterexample.out");
int main()
{
  long long n ,i , l ,r;
  cin>>l>>r;
  if(l == r)
    cout<<"-1";
  if(l + 1 == r)
    cout<<"-1";
  if(l + 2 == r){
    if(l%2 == 0)
      cout<<l<<" "<<l + 1<<" "<<r;
    else
      cout<<"-1";
  } if(l + 2 < r){
    if(l%2 == 0)
      cout<<l<<" "<<l + 1<<" "<<l + 2;
    else
      cout<<l + 1<<" "<<l + 2<<" "<<l + 3;
  }
  return 0;
}