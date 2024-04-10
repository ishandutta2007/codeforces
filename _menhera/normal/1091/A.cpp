#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
  cin >>a>>b>>c;
  b -= 1;
  c -= 2;
  cout << min({a, b, c})*3 + 3 << endl;
}