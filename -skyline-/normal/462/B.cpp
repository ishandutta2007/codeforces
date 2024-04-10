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
#define ll    long long  
using namespace std;
long long n,k,a[200];
priority_queue<long long> pq;
int main()
{
    char c[100005];
    scanf("%d %d",&n,&k);
    long long i,s=0;
    scanf("%s",&c);
    for(i=0;i<n;i++){
                      a[c[i]-'A']++;  
    }
    sort(a,a+26);
    for(i=25;i>=0;i--){
        if(k<=a[i]){
            s+=1ll*k*k;
            printf("%I64d\n",s);
            return 0;
        }
        else{
            s+=1ll*a[i]*a[i];
            k-=a[i];
        }
    }
    return 0;
}