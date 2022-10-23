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
    char c[3000];
    string s;
    int i,j,k,l,n;
    cin>>c>>n;
    s=c;
    i=0;
    
    while(n!=0&&i<s.size()){
                            k=c[i];
                            l=i;
                            for(j=i+1;j<=i+n&&j<=s.size();j++){
                                                  if(c[j]>k){
                                                             k=c[j];
                                                             l=j;
                                                  }
                            }
                            if(l==i){
                                     i++;
                                     continue;
                            }
                                     
                            n-=(l-i);
                            char ch=c[l];
                            for(j=l-1;j>=i;j--)c[j+1]=c[j];
                            c[i]=ch;
                            i++;
                                                  
                                                             
    }
    cout<<c<<endl;            
                                    
                
                
//system("pause");
    return 0;
}