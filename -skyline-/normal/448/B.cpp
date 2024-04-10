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
int a[270],b[270];
int main()
{
    string s,t;
    cin>>s>>t;
    int i,j,k,l;
    for(i=0;i<s.size();i++){
                        char c=s[i];
                        a[c]++;
    }
    for(i=0;i<t.size();i++){
                        char c=t[i];
                        b[c]++;
    }
    bool array=1,f=1,automaton=1;
    for(i=0;i<=260;i++){
                        if(a[i]<b[i])f=0;
                        if(a[i]!=b[i])array=0;
    }
    if(f==0){
             cout<<"need tree"<<endl;
             return 0;
    }
    if(array==1){
                 cout<<"array"<<endl;
                 return 0;
    }
    j=0;
    for(i=0;i<s.size();i++){
                                      
                            if(s[i]==t[j])j++;
                            if(j>=t.size()){
                                           break;
                            }
                            
    }
    if(j!=t.size())automaton=0;                    
    if(automaton==1){
                     cout<<"automaton"<<endl;
    }
    else{
         cout<<"both"<<endl;
    }
                          
                     
    
   // system("pause");
    return 0;
}