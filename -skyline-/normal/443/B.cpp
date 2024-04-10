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
    string s;
    int k,i,j,l,ans=0;
    cin>>s>>k;
    for(i=0;i<s.size();i++){
                        string c=s.substr(i);
                        for(j=1;j*2<=(c.size()+k);j++){
                                                     bool f=1;
                                                     for(l=0;l<j;l++){
                                                                      if((l+j)>=c.size()) break;
                                                                      if(c[l]!=c[l+j]) f=0;
                                                     }
                                                     if(f==1)ans=max(ans,j);
                        }
    }
    cout<<2*ans<<endl;
                        
                                                     
                                                                      
	//system("pause");
	return 0;
}