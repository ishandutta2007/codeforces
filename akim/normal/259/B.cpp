#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int main()
{
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
 int a1,a2,a3,a4,a5,a6,a7,a8,a9;
 cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
 for(a1=1;a1<=100000;a1++)
 {
  a5=a1+a2+a3-a4-a6;
  a9=a1+a2+a3-a7-a8;
  int s=a1+a2+a3;
  if(a1+a2+a3==s&&a4+a5+a6==s&&a7+a8+a9==s&&a1+a4+a7==s&&a2+a5+a8==s&&a3+a6+a9==s&&a1+a5+a9==s&&a7+a5+a3==s)
  {
   cout<<a1<<" "<<a2<<" "<<a3<<endl;
   cout<<a4<<" "<<a5<<" "<<a6<<endl;
   cout<<a7<<" "<<a8<<" "<<a9<<endl;
   return(0);
  }
 }
}