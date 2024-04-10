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
map<char,int> m;
int main()
{
    m['A']=0;
    m['B']=0;
    m['C']=0;
    char a,b,c;
    int i;
    for(i=1;i<=3;i++){
                      cin>>a>>b>>c;
                      if(b=='>')m[a]++;
                      else m[c]++;
    }
    string s="";
    for(i=0;i<3;i++){
                     for(a='A';a<='C';a++){
                                           if(m[a]==i){
                                                       s+=a;
                                                       break;
                                           }
                     }
    }
    if(s.size()!=3)s="Impossible";
    cout<<s<<endl;                                                                           
	//system("pause");
	return 0;
}