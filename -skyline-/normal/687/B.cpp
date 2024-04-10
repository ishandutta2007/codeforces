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
int n,k,a[1000005],b[30],c[30],x;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int t=k;
    for(int i=2;i<=k;i++){
            int o=1;
            while(t%i==0)t/=i,o*=i;
            if(o>1)b[++x]=o;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=x;j++)if(a[i]%b[j]==0)c[j]=1;
    }
    bool oh=0;
    for(int i=1;i<=x;i++)if(!c[i])oh=1;
    if(oh)printf("No\n");
    else printf("Yes\n");
//	system("pause");
	return 0;
}