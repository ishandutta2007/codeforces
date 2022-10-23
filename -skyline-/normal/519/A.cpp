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
int s;
int main()
{
    for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                    char c;
                    cin>>c;
                    if(c=='.') continue;
                    int k=1;
                    if(c<'a') c+=32,k=-1;
                    if(c=='q')k*=9;
                    else if(c=='r')k*=5;
                    else if(c=='b'||c=='n')k*=3;
                    else if(c=='k')k=0;
                    s+=k;
            }
    }
    if(s>0)cout<<"Black"<<endl;
    else if(s)cout<<"White"<<endl;
    else cout<<"Draw"<<endl;
	//system("pause");
	return 0;
}