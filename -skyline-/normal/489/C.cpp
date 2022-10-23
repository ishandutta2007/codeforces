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
int l,n,a[105],b[105],t;
int main()
{
    scanf("%d%d",&l,&n);
    if(l==1&&n==0){
                   printf("0 0\n");
                   return 0;
    }
    if(l*9<n||n<1){
                   printf("-1 -1\n");
                   return 0;
    }
    t=n-1;
    a[1]=1;
    for(int i=l;i>0;i--){
            a[i]+=min(9,t);
            t-=a[i];
    }
    for(int i=1;i<=l;i++){
            b[i]=min(9,n);
            n-=b[i];
    }
    for(int i=1;i<=l;i++)printf("%d",a[i]);
    printf(" ");
    for(int i=1;i<=l;i++)printf("%d",b[i]);
    printf("\n");
	//system("pause");
	return 0;
}