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
//:
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n<4){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n&1){
		printf("4 * 5 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24\n");
		for(int i=6;i<=n;i+=2){
			printf("%d - %d = 1\n24 * 1 = 24\n",i+1,i);
		}
	}
	else{
		printf("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
		for(int i=5;i<=n;i+=2){
			printf("%d - %d = 1\n24 * 1 = 24\n",i+1,i);
		}
	}
	return 0;
}