#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
using namespace std;
#define LL          long long
#define MOD         (1000000007LL)
struct BIT{
       static const long long N=1200000;
       long long x[N];
       void add(long long k,long long a){
            for(;k<N;k=k|=k+1)x[k]=(x[k]+a)%MOD;
       }
       long long sum(long long k){
           long long s=0;
           for(;k>=0;k=(k&(k+1))-1)s=(s+x[k])%MOD;
           return s;
       }
       long long at(long long k){
           return k==0?sum(0):(sum(k)-sum(k-1)+MOD)%MOD;
       }
}bit;
                    
       
long long n,a[200000];


int main()
{
    long long i,j,k,l;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    bit.add(0,1);
    for(i=0;i<n;i++){
             const long long way=bit.sum(a[i])*a[i];
             bit.add(a[i],way-bit.at(a[i]));
    }
    cout<<((bit.sum(1100000)-1+MOD)%MOD)<<endl;         
    //system("pause");
    return 0;
}