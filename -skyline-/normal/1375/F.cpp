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
using namespace std;
ll a[4],b[4];
int main(){
    scanf("%I64d%I64d%I64d",a+1,a+2,a+3);
    printf("First\n");
    fflush(stdout);
    ll x=max(a[1],max(a[2],a[3]))-min(a[1],min(a[2],a[3])),y;
    printf("%I64d\n",x);
    fflush(stdout);
    scanf("%I64d",&y);
    if(!y) return 0;
    a[y]+=x;
    x=max(a[1],max(a[2],a[3]))*3ll-a[1]-a[2]-a[3];
    printf("%I64d\n",x);
    fflush(stdout);
    scanf("%I64d",&y);
    if(!y) return 0;
    a[y]+=x;
    x=max(a[1],max(a[2],a[3]))-min(a[1],min(a[2],a[3]));
    printf("%I64d\n",x/2);
    fflush(stdout);
    scanf("%I64d",&y);
    //system("pause");
    return 0;
}