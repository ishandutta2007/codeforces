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
#define ll   long long
//:
using namespace std;
int n,k;
string x="1",t;
bool f;
int main()
{
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++){
            cin>>t;
            if(t=="0")f=1;
            else{
                 if(t[0]!='1')x=t;
                 else{
                      bool b=1;
                      int l=t.size();
                      for(int i=1;i<l;i++){
                              if(t[i]!='0')i=l,x=t,b=0;
                      }
                      if(b)k+=l-1;
                 }
            }
    }
    if(f)printf("0\n");
    else{
         cout<<x;
         for(int i=1;i<=k;i++)printf("0");
         printf("\n");
    }
  //  system("pause");
    return 0;
}