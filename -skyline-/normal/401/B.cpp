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
bool f[4100];
int main()
{
    int n,k,i,j,s,c,d,x;
    cin>>n>>k;
    f[n]=1;
    n=n-1;
    for(i=1;i<=k;i++){
                      cin>>s;
                      for(j=1;j<=3-s;j++)cin>>c,f[c]=1;
    }
    c=0;
    d=0;
    x=0;
    for(i=1;i<=n+1;i++){
                      if(f[i]==0)c++;
                      else d+=c,x+=((c+1)/2),c=0;
    }
    cout<<x<<' '<<d<<endl;                
                                                  
    //system("pause");
    return 0;
}