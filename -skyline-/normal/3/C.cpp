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
char c[777],a;
int i,j,k,l,o,x,ow,xw;

inline int che(int o,int p,int q){
    bool b=(c[p]==c[q]&&c[q]==c[o]&&c[o]==a);
    int ans=b;
    return ans;
}

int main()
{
    
    for(i=1;i<=9;i++)cin>>c[i],o+=(c[i]=='0'),x+=(c[i]=='X');
    a='0';
    ow+=che(1,4,7);
    ow+=che(2,5,8);
    ow+=che(3,6,9);
    ow+=che(1,2,3);
    ow+=che(4,5,6);
    ow+=che(7,8,9);
    ow+=che(1,5,9);
    ow+=che(3,5,7);
    a='X';
    xw+=che(1,4,7);
    xw+=che(2,5,8);
    xw+=che(3,6,9);
    xw+=che(1,2,3);
    xw+=che(4,5,6);
    xw+=che(7,8,9);
    xw+=che(1,5,9);
    xw+=che(3,5,7);
    if((x-o)>=2||o>x||ow*xw>0||(ow==1&&x>o)||(xw==1&&o==x)){
                                                               puts("illegal");
    }
    else if(ow>0)puts("the second player won");
    else if(xw>0)puts("the first player won");
    else if(o+x==9)puts("draw");
    else if(x>o)puts("second");
    else puts("first");                                                           
    //system("pause");
    return 0;
}