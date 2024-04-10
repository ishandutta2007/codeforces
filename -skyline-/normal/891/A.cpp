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
int n,a[2005],ans,f[2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if(a[i]==1)f[1]++;
            else f[0]++;
    }
    if(f[1]){
             printf("%d\n",f[0]);
             return 0;
    }
    ans=-1;
    a[n+1]=1;
    for(int i=1;i<=n;i++){
            int o=a[i];
            int j=i;
            while(o!=1)o=__gcd(o,a[++j]);
            if(j==n+1) break;
            int res=j-i+n-1;
            if(ans==-1||ans>res)ans=res;
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}