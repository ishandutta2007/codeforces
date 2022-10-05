#include <bits/stdc++.h>

using namespace std;

const long double eps=0.0000000001;
long double a,b;
int main()
{

cin>>a>>b;
b=pow(b, a/b);
if (abs(a-b)<eps)
  {
  cout<<'=';
  return 0;
  }
if (a>=b)
  cout<<'>';
if (a<b)
  cout<<'<';



    return 0;
}