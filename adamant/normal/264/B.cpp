#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n,primes[100010],rad,x,y,sol,D[100010],p;
bool neprim[100010];

void ciur()
{
int i,j;
for(i=2;i<=100000;i++)
if(!neprim[i])
{
              primes[++p]=i;
              for(j=i+i;j<=100000;j+=i)neprim[j]=1;
}     
}

int main()
{
 int i,j;
 cin>>n;
 ciur();
 if(n==1)
 {
 cout<<1<<endl;
 return 0;
}
 
 for(i=1;i<=n;i++)
 {
                  cin>>x;
                  y=x;
                  sol=0;
                  for(j=1;j<=p and primes[j]<=x;j++)
                  if(x%primes[j]==0)
                  {
                                    while(x%primes[j]==0)x/=primes[j];
                                    sol=max(sol,D[primes[j]]);
                  }
                  
                  for(j=1;j<=p and primes[j]<=y;j++)
                  if(y%primes[j]==0)
                  {
                                    while(y%primes[j]==0) y/=primes[j];
                                    D[primes[j]]=sol+1;
                  }
 }
 sol=0;
 for(i=1;i<=100000;i++)
 sol=max(sol,D[i]);
 cout<<sol<<endl;
 return 0;
 }