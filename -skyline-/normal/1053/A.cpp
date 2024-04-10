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
ll n,m,k;
int main(){
    cin>>n>>m>>k;
    if(n*m*2ll%k!=0){
        puts("NO");
        return 0;
    }
    ll o=__gcd(n,k);
    if(o>1ll){
        puts("YES");
        puts("0 0");
        if(k==o){
            printf("%I64d 0\n",n*2ll/o);
            printf("0 %I64d\n",m/(k/o));
        }
        else{
            printf("%I64d 0\n",n/o);
            printf("0 %I64d\n",m*2ll/(k/o));
        }
    }
    else{
        puts("YES");
        puts("0 0");
        printf("%I64d 0\n",n);
        printf("0 %I64d\n",m*2ll/k);
    }
//	system("pause");
	return 0;
}