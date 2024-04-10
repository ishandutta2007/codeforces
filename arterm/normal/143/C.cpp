#include <cstdlib>
#include <iostream>
#include <math.h>
#include <set>

#define long long long

using namespace std;


long v[10000],amin=2000000000000000000LL,amax=0;
set<long> s;

void add(long p){
     long u=0;
     for (set<long>::iterator i=s.begin(); i!=s.end(); ++i)
     v[u++]=(*i)*p;
     for (long i=0; i<u; ++i)
     s.insert(v[i]);
     }
     

void findp(long x){
     long i;
     for (i=2; i*i<=x; ++i)
     if (x%i==0){
                 add(i);
                 x/=i;
                 --i;
                 }
     if (x>1)
     add(x);
     }
     
long sl(long b){
     long h=(long)sqrt(b);
     while (b%h!=0)
     --h;
     return h;
     }
     
          
void fma(long a, long b){
     long h,l,slw=sl(b);
     l=(a+1)*(b+2)*(1+2);
     for (set<long>::iterator i=s.begin(); i!=s.end() && (*i)*(*i)<=b; ++i)
     if (b%(*i)==0)
     l=min(l,((a+1)*(b/(*i)+2)*((*i)+2)));
     h=(a+1)*(slw+2)*(b/slw+2);
     amin=min(l,amin);
     amax=max(h,amax);
     }

int main()
{
    long n,a,b,c;
    s.insert(1);
    cin>>n;
    findp(n);
    for (set<long>::iterator i=s.begin(); i!=s.end(); ++i)
    fma(*i,n/(*i));
    cout<<amin-n<<" "<<amax-n;
    return 0;
}