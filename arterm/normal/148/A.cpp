#include <cstdlib>
#include <iostream>

#define long long long

using namespace std;

long p[10];

long gcd(long x, long y){
     while (x!=0){
           y%=x;
           swap(x,y);
           }
     return y;
     }
     
long lcm(long x, long y){
     return x/gcd(x,y)*y;
     }

long f(long n){
     long u=(1<<4)-1,a,d,i,s,ans=0;
     for(;u>0;--u){
                   a=1;
                   d=1;
                   i=0;
                   s=0;
                   while(a<=u){
                               if (a&u){
                                  ++s;
                                  d=lcm(d,p[i]);
                                  }
                               ++i;
                               a<<=1;
                               }
                   if (s%2!=0)
                   ans+=(n/d);
                   else
                   ans-=(n/d);
                   }
     return ans;
     }


int main()
{
    long d,ans=0;
    cin>>p[0];
    for (long i=1; i<4; ++i)
    cin>>p[i];
    cin>>d;
    cout<<f(d);
    //system("PAUSE");
    return 0;
}