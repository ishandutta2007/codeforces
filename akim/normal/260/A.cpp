#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int a,b,n;
 cin>>a>>b>>n;
 if((a*10+0)%b==0){cout<<a<<0;}else
 if((a*10+1)%b==0){cout<<a<<1;}else
 if((a*10+2)%b==0){cout<<a<<2;}else
 if((a*10+3)%b==0){cout<<a<<3;}else
 if((a*10+4)%b==0){cout<<a<<4;}else
 if((a*10+5)%b==0){cout<<a<<5;}else
 if((a*10+6)%b==0){cout<<a<<6;}else
 if((a*10+7)%b==0){cout<<a<<7;}else
 if((a*10+8)%b==0){cout<<a<<8;}else
 if((a*10+9)%b==0){cout<<a<<9;}else
  {cout<<-1;return(0);}
 for(n=n-1;n>0;n--){cout<<0;}
}