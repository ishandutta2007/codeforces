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
//:
using namespace std;
string s,e;
long long r,x,k,moder=1000000007;
int main()
{
    cin>>s;
    cin>>e;
    cin>>k;
    if(s.size()!=e.size()){
                           printf("0\n");
                           return 0;
    }
    bool b=0;
    for(int i=0;i<s.size();i++){
            string s2="";
            for(int j=i;j<i+s.size();j++)s2=s2+s[j%s.size()];
            if(s2==e){
                      b=1;
                      break;
            }
    }
    if(!b){
         printf("0\n");
         return 0;
    }
    for(x=s.size();x>0;x--){
                            if(s.size()%x) continue;
                            r=s.size()/x;
                            bool b=0;
                            for(int i=0;i<r;i++){
                                    for(int j=i+r;j<s.size();j+=r){
                                            if(s[j]!=s[i]){
                                                           b=1;
                                                           i=r;
                                                           break;
                                            }
                                    }
                            }
                            if(!b) break;
    }
    long long y=(s==e),n=y^1;
    while(k--){
               long long t=((x-1)*y%moder+x*n%moder)%moder;
               n=((s.size()-x)*y%moder+(s.size()-x-1)*n%moder)%moder;
               y=t;
    }
    printf("%I64d\n",y);                                                 
	//system("pause");
	return 0;
}