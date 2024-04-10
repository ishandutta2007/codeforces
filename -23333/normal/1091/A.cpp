#include <bits/stdc++.h>
using namespace std;
int main()
{
  int x,y,z;
  cin>>x>>y>>z;
  int k=min(min(x,y-1),z-2);
  cout<<3*k+3<<endl; 
}