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
char s[600000],c[600000];
int main()
{
    int a,b,i,j,k,l,f[600000]={0},g=0;
    
    char q,z,aa='A',bb='B',cc='C';
    cin>>a>>b>>s;
    if(a==1){
             cout<<0<<endl;
             cout<<s<<endl;
            // system("pause");
             return 0;
    }
             
    if(b==2){
             
             for(i=0;i<a;i++){
                              g+=((i%2+aa)!=s[i]);
                              s[i]=i%2+aa;
                              c[i]=aa+bb-s[i];
             }
             if(g<a-g){
                                   
                       cout<<g<<endl;
                       cout<<s<<endl;
             }
                       
             else{
                  cout<<a-g<<endl;
                  cout<<c<<endl;
             }
                  
            // system("pause");
                            
             return 0;
    }
    for(i=1;i<a-1;i++){
                       if(s[i]==s[i-1]){
                                      g++;
                                      if(s[i-1]!='A'&&s[i+1]!='A')s[i]='A';
                                      else if(s[i-1]!='B'&&s[i+1]!='B') s[i]='B';
                                      else  s[i]='C';
                     }
    }
    if(s[a-1]==s[a-2]){
                     g++;
                     if(s[a-2]!='A')s[a-1]='A';
                     else s[a-1]='C';
    }     
    cout<<g<<endl;
    cout<<s<<endl;            
                                               
                              
	//system("pause");
	return 0;
}