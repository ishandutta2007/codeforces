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
string s;
char v[1000005];
int o,a,n;
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('||c=='['||c=='<'||c=='{')a++;
            else a--;
            if(a<0)a=-123456;
    }
    if(a){
          printf("Impossible\n");
          return 0;
    }
    for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='<'||c=='{'||c=='('||c=='['){
                                               v[++o]=c;
                                               continue;
            }
            if(c=='}')c='{';
            else if(c=='>')c='<';
            else if(c==')')c='(';
            else c='[';
            if(v[o--]!=c)a++;
    }
    printf("%d\n",a);        
  //  system("pause");
    return 0;
}