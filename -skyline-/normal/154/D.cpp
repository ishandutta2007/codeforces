//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
//:
using namespace std;
//
//
int x,y,a,b,f=1;
int main()
{
    scanf("%d%d%d%d",&x,&y,&a,&b);
    if(x>y)f=-1,x=-x,y=-y,a=-a,b=-b,swap(a,b);
    if(x+a<=y&&x+b>=y){
                       printf("FIRST\n%d\n",f*y);
                       return 0;
    }
    if((a<=0&&b>=0)||b<0||(a+b<=0)||x+a>y){
                          printf("DRAW\n");
                          return 0;
    }
    int o=(y-x)%(a+b);
    if(o==0)printf("SECOND\n");
    else if(o<a||o>b)printf("DRAW\n");
    else printf("FIRST\n%d\n",f*o+f*x);
//	system("pause");
	return 0;
}