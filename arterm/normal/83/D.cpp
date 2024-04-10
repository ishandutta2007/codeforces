#include <cstdlib>
#include <iostream>

#define long long long
#define C 100100
#define M 100100
#define P 80

using namespace std;

bool u[C];
long p[M];

bool prime(long x){
     for (long i=2; i*i<=x; ++i)
     if (x%i==0)
     return 0;
     return 1;
     }
     
void erat(long k){
     p[0]=0;
     for (long i=0; i<C; ++i)
     u[i]=0;
     for (long i=2; i<k; ++i)
     if (!u[i]){
                p[++p[0]]=i;
                for (long j=2; j*i<k; ++j)
                u[i*j]=1;
                }
     }
     
bool check(long x){
     for (long i=1; i<=p[0]; ++i)
     if (x%p[i]==0)
     return 0;
     return 1;
     }
     
     

long f(long n, long h){
     long u=(1<<p[0])-1,a,d,i,s,ans=n-h;
     for(;u>0;--u){
                   a=1;
                   d=1;
                   i=1;
                   s=0;
                   while(a<=u){
                               if (a&u){
                                  ++s;
                                  d*=p[i];
                                  }
                               ++i;
                               a<<=1;
                               }
                   if (s%2!=0)
                   ans-=((n/d)-(h/d));
                   else
                   ans+=((n/d)-(h/d));
                   }
     return ans;
     }

int main()
{
    long a,b,k,l,r,ans=0;
    cin>>a>>b>>k;
    if (!prime(k)){
                   cout<<0;
                   return 0;
                   }
    l=(a+k-1)/k;
    r=b/k;
    if (k>=C-100){
                  if (l<=1 && 1<=r)
                  cout<<1;
                  else
                  cout<<0;
                  return 0;
                  }
    else{
         erat(k);
         if (k>P)
         for (long i=l; i<=r; ++i)
         if(check(i))
         ++ans;
         if(k<P)
         ans=f(r,l-1);
         }
    cout<<ans;
    //system("PAUSE");
    return 0;
}