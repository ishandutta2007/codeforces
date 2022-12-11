#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 int n,i;
 cin>>n;
 if((n==1)||(n==2)){cout<<"-1";return(0);}
 if(n==3){cout<<"210";return(0);}
 int m=1;
 for(i=2;i<=n;i++){m=(m*10)%210;};
 m=210-m;
 cout<<"1";
 for(i=2;i<=n-3;i++){cout<<"0";}
 if(m<=99){cout<<"0";}
 if(m<=9){cout<<"0";}
 cout<<m;
 return(0);
}