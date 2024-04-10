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
map<char,string> im;
map<int,int> a,h;
int main()
{                  
    cin>>im['h'];
    cin>>im['a'];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
            int m,hh;
            char cc,c;
            string s;
            cin>>m>>c>>hh>>cc;
            s=im[c];
            if(cc=='y'&&c=='h'){
                                h[hh]++;
                                if(h[hh]>1){
                                           h[hh]=-99999;
                                           cout<<s<<' '<<hh<<' '<<m<<endl;
                                }
            }
            if(cc=='y'&&c=='a'){
                                a[hh]++;
                                if(a[hh]>1){
                                           a[hh]=-99999;
                                           cout<<s<<' '<<hh<<' '<<m<<endl;
                                }
            }
            if(cc=='r'&&c=='h'){
                                h[hh]+=2;
                                if(h[hh]>1){
                                           h[hh]=-99999;
                                           cout<<s<<' '<<hh<<' '<<m<<endl;
                                }
            }
            if(cc=='r'&&c=='a'){
                                a[hh]+=2;
                                if(a[hh]>1){
                                           a[hh]=-99999;
                                           cout<<s<<' '<<hh<<' '<<m<<endl;
                                }
            }       
    }     
	//system("pause");
	return 0;
}