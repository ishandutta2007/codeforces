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
string A,B;
long long a,c,ans=1;
long long fpower(long long x,long long k){
     long long ans=1;
     while(k){
              if(k&1) ans=ans*x%c;
              k>>=1;
              x=x*x%c;
     }
     return ans;
}
int main()
{
    cin>>A>>B>>c;
    int al=A.size(),bl=B.size();
    for(int i=0;i<al;i++)a=(a*10+A[i]-48)%c;
    if(B=="1"){
               printf("%I64d\n",a==1?c:(a+c-1)%c);
               return 0;
    }
    int i=bl-1;
    while(B[i]==48)B[i--]='9';
    B[i]--;
    for(int i=0;i<bl;i++){
            ans=fpower(ans,10)*fpower(a,B[i]-48)%c;
    }
    ans=ans*(a+c-1)%c;
    if(!ans) ans=c;
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}