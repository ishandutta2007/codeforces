#include <iostream>
#define ll long long 
using namespace std;
ll i,j,n,m,a,b,c,sc;
int main()
{
 cin >> a >> b >> c;
 cin >> n;
 ll sc=0;
 for(i=0;i<n;i++)
 { 
  ll x;
  cin >> x;
  if(b<x && x<c)sc++;                         
 }
 cout << sc << endl;
 return 0;
}