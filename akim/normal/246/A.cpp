#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 int n,i;
 cin>>n;
 if((n==1)||(n==2)){cout<<"-1";return(0);}
 for(i=n;i>0;i--){cout<<i<<" ";}
 return(0);
}