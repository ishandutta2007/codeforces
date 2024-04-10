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
int main()
{
    int t,w;
    t=-1000000005;
    w=-t;
    int q,n;
    cin>>q;
    int i;
    string bnm;
    char ew;
    for(i=1;i<=q;i++){
                      cin>>bnm;
                      cin>>n;
                      cin>>ew;
                      if(ew=='N'){
                                  if(bnm.size()==2) bnm='<'+'>'-bnm[0];
                                  else bnm='<'+'>'-bnm[0],bnm+='=';
                      }
                                  
                      if(bnm.size()==1)n+=(bnm[0]=='<'?-1:1);
                      if(bnm[0]=='<')w=min(w,n); else t=max(t,n);
    }
    if(t>w) cout<<"Impossible"<<endl;
    else{
         cout<<w<<endl;
    }              
    //system("pause");
    return 0;
}