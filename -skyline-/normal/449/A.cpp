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
int main()
{
    long long x,y,k,i,j,l,ans=1;
    cin>>x>>y>>k;
    if(k>(x+y-2)){
                  puts("-1");
                  return 0;
    }
    long long longlong;
    if(sqrt(x)>k/2)longlong=k/2;
    else longlong=sqrt(x);              
    for(i=0;i<=longlong;i++){
                              j=k-i;
                              long long xx=x/(i+1),yy=y/(j+1);
                              if(xx*yy>ans)ans=xx*yy;
                              xx=y/(i+1),yy=x/(j+1); 
                              if(xx*yy>ans)ans=xx*yy;
    }
    if(k>(x+y)/2){
                  if(k>=x&&k>=y){
                               if(x/(k-y+2)>ans)ans=x/(k-y+2);
                               if(y/(k-x+2)>ans)ans=y/(k-x+2);
                  }
                  else if(x>y)ans=y;
                  else ans=x;
    }
                  
                  
                               
    cout<<ans<<endl;                  
                      
                      
                      
    //system("pause");
    return 0;
}