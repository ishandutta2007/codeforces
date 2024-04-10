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
char a[305][305],k,t,c;
int main()
{
    int i,n,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    bool no=0;
    k=a[0][0];
    t=a[0][1];
    if(k==t)no=1;
    for(i=0;i<n;i++){
                     if(no==1)break;
                     for(j=0;j<n;j++){
                                      if(no==1)break;
                                      c=a[i][j];
                                      if(i==j||i+j==n-1){
                                                         if(k!=c)no=1;
                                      }
                                      else if(t!=c)no=1;
                     }
    }
    puts(no==0?"YES":"NO");              
                                      
    //system("pause");
    return 0;
}