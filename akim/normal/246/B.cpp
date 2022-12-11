#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 int n,m,i,s;
 s=0;
 cin>>n;
 for(i=1;i<=n;i++){cin>>m;s=s+m;}
 if(s%n==0){cout<<n;}else{cout<<n-1;}
 return(0);
}