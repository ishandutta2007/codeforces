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
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                          printf("YES\n0\n");
                          return 0;
            }
    }
    s="00"+s;
    for(int i=0;i<s.size()-2;i++){
            for(int j=i+1;j<s.size()-1;j++){
                    for(int k=j+1;k<s.size();k++){
                            int ans=s[i]*100+s[j]*10+s[k];
                            if(ans%8==0){
                                         printf("YES\n%d\n",ans-5328);                                   
                                      //   system("pause");
                                         return 0;
                            }
                    }
            }
    }
    printf("NO\n");          
    return 0;
}