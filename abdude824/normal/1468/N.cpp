#include <bits/stdc++.h>
using namespace std;
int main() {
   int t;
   cin>>t;
   while(t--)
   {
       int x,y,z;
       cin>>x>>y>>z;
       int a,b,c,d,e;
       cin>>a>>b>>c>>d>>e;
       int sum=a+d;
       int sum1=b+e;
       //cout<<sum<<" "<<sum1<<" ";
       if(x+z>=sum)
       {
           if(x>=a)
           {
          sum-=x;
          if(sum>0)
          {
          z-=sum;
          }
          if(y+z>=sum1)
          {
              if(y>=b)
              {
              sum1=sum1-y;
              //cout<<"sum1"<<sum1<<" ";
              //cout<<z<<" ";
              if(sum1>0)
              {
              z=z-sum1;
              }
              //cout<<z<<" ";
              if(z>=c)
              {
                  cout<<"Yes"<<"\n";
              }
              else
              cout<<"No"<<"\n";
              }
              else 
              {
                  cout<<"No"<<"\n";
              }
          }
          else 
          {
              cout<<"No"<<"\n";
          }
           }
           else 
           {
               cout<<"No"<<"\n";
           }
       }
       else 
       {
           cout<<"No"<<"\n";
       }
   }
}