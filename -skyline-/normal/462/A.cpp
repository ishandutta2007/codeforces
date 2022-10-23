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
int f[200][200];
int main()
{
    int i,j,k,l,n;
    cin>>n;
    for(i=1;i<=n;i++){
                      for(j=1;j<=n;j++){
                                        char c;
                                        cin>>c;
                                        if(c=='o'){
                                                   f[i-1][j]++;
                                                   f[i+1][j]++;
                                                   f[i][j-1]++;
                                                   f[i][j+1]++;
                                        }
                      }
    }
    for(i=1;i<=n;i++){
                      for(j=1;j<=n;j++){
                                        if(f[i][j]%2==1){
                                                         cout<<"NO"<<endl;
                                                         return 0;
                                        }
                      }
    }
    cout<<"YES"<<endl;                         
                                                    
    //system("pause");
    return 0;
}