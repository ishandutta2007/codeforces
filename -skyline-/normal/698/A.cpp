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
int n,a[105],f[105][5],s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
            f[i][0]=max(max(f[i-1][0],f[i-1][1]),max(f[i-1][2],f[i-1][3]));
            if(a[i]==1||a[i]==3)f[i][1]=max(1+max(f[i-1][0],f[i-1][2]),max(f[i-1][1],f[i-1][3]));
            if(a[i]==2||a[i]==3)f[i][2]=max(1+max(f[i-1][0],f[i-1][1]),max(f[i-1][2],f[i-1][3]));
            if(a[i]==3)f[i][3]=max(1+f[i-1][0],max(f[i-1][1],max(f[i-1][2],f[i-1][3])));
            s=max(s,f[i][0]);
            s=max(s,f[i][1]);
            s=max(s,f[i][2]);
            s=max(s,f[i][3]);
    }
    int ans=n-s;
    printf("%d\n",ans);
//	system("pause");
	return 0;
}