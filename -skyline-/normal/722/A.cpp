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
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//
int a,b,c;
char cc;
int main()
{
    scanf("%d",&a);
    scanf(" %c",&cc);
    b=cc-'0';        
    scanf(" %c",&cc);
    b=b*10+cc-'0';
    scanf(" %c",&cc);
    scanf(" %c",&cc);
    c=cc-'0';
    scanf(" %c",&cc);
    c=c*10+cc-'0';
    if(c>59)c=c%10;
    if(a==12){
              if(b>12){
                       if(b>19)b=b%10;
                       else b=12;
              }
              if(b==0)b=10;
    }
    else if(b>23)b=b%10;
    printf("%02d:%02d\n",b,c);
//	system("pause");
	return 0;
}