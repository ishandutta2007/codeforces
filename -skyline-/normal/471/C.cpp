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
using namespace std;
long long n,a[1400006];
int main()
{
    long long i,j,k,l;
    cin>>n;
    for(i=1;i<=1400000;i++)a[i]=a[i-1]+i;
    for(i=1;i<=1400000;i++){
                            a[i]=a[i]*3-i;
                            if(a[i]>n) break;
    }
    while(a[i]>n||a[i]==n+1)i--;
    if(n%3==0)i=i/3;
    else if(n%3==1)i=(i+1)/3;
    else i=(i+2)/3;
    cout<<i<<endl;                        
   // system("pause");
    return 0;
}