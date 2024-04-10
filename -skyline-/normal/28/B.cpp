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
int n,a[300],s,u[300],fi,it,c[300];
bool f[300][300];
inline void ope(int x){    
       c[x]=s;
       for(int i=1;i<=n;i++){
               if(!c[i]&&f[i][x]) ope(i);
       }
}       
                    
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=i)s++;
            u[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
            if(!u[i]){
                      puts("NO");
                      return 0;
            }
    }        
    if(!s){
           puts("YES");
           return 0;
    }
    int k;
    for(int i=1;i<=n;i++){
            cin>>k;
            if(i-k>0)f[i][i-k]=f[i-k][i]=1;
            if(i+k<=n)f[i][i+k]=f[i+k][i]=1;
    }
    s=0;
    for(int i=1;i<=n;i++)if(!c[i])s++,ope(i);
    for(int i=1;i<=n;i++){
            if(c[i]!=c[a[i]]){
                              puts("NO"); 
                              return 0;
            }
    }                     
    puts("YES");                                                   
  //  system("pause");
    return 0;
}