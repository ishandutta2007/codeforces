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
int a[120][120];
int main()
{
    int i,j,x,y;
    cin>>x>>y;
    for(i=1;i<=x;i++){
                      for(j=1;j<=y;j++)cin>>a[i][j];
    }
                      
    while(x%2==0){
                  int c=x/2;
                  int f=0;
                  for(i=1;i<=c;i++){
                                    for(j=1;j<=y;j++)if(a[i][j]!=a[x+1-i][j])f=1;
                                    if(f==1) break;
                  }
                  if(f==0)x=x/2; else break;
    }
    cout<<x<<endl;                                
    //system("pause");
    return 0;
}