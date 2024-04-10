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
int n,a[100005],s,ans1,ans2,x[2],o;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            char c;
            scanf(" %c",&c);
            if(c=='r')a[i]=1;
    }
    for(int i=1;i<=n;i++){
            if(a[i]!=o)x[o]++;
            o^=1;
    }
    ans1=max(x[0],x[1]);
    x[0]=x[1]=0;
    o=1;
    for(int i=1;i<=n;i++){
            if(a[i]!=o)x[o]++;
            o^=1;
    }
    ans2=max(x[0],x[1]);
    printf("%d\n",min(ans1,ans2));
//	system("pause");
	return 0;
}