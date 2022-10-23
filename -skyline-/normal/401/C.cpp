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
int main()
{
    int m,n;
    cin>>m>>n;
    if((n<m-1)||(n>m*2+2)){
                           cout<<-1<<endl;
                           return 0;
    }
    if(n<=m){
             bool k=0;
             int i;
             for(i=1;i<=m+n;i++)cout<<k,k=1-k;
             cout<<endl;
             return 0;
    }
    if(n>2*m){
              int i,k=(m+n)/3;
              for(i=1;i<=k;i++)cout<<"110";
              for(i=1;i<=m+n-3*k;i++)cout<<1;
              cout<<endl;
              return 0;
    }
    int i,l=n-m;
    for(i=1;i<=l;i++)cout<<"110";
    for(i=1;i<=(m-l);i++)cout<<"10";
    cout<<endl;                                                    
    //system("pause");
    return 0;
}