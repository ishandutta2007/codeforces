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
#define LL    long long
long long n,ans;

inline void ope(long long luc,long long a,long long b){
       if(luc>n*100LL) return;
       if(a==b&&luc>=n){
                       ans=min(ans,luc);
       }
       ope(luc*10LL+4LL,a+1LL,b);
       ope(luc*10LL+7LL,a,b+1LL);
}
       
                       
int main()
{
    ans=999*999*999*200LL;
    cin>>n;
    ope(0LL,0LL,0LL);
    cout<<ans<<endl;
   // system("pause");
    return 0;
}