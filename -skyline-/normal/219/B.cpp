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
inline long long jc(long long k){
       long long x=10,y=1;
       return (k==0?y:x*jc(k-1));
}

inline int di(long long x){
       int n=0;
       while(x%10==9)n++,x/=10;
       return n;
}
              
int main()
{
    long long a,b,i,j,k,l;
    cin>>a>>b;
    b=a-b;
    
    for(i=18;i>=1;i--){
                       k=jc(i);
                       if(k>a) continue;
                       l=a%k;
                       k=a-l-1;
                       if(k>=b){
                                if(di(k)<=di(a))k=a;
                                cout<<k<<endl;
                                return 0;
                       }
    }
    cout<<a<<endl;                   
                                
	//system("pause");
	return 0;
}