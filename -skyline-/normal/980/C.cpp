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
int f[600],b[600],n,k,a[100005];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        if(b[x]==2){
            int l=x;
            while(l>=0&&b[l]==2)b[l]=1,--l;
        }
        if(b[x]){
            a[i]=f[x];
            continue;
        }
        int l=x;
        while(l>x-k+1&&l&&b[l-1]!=1)--l;
        for(int i=l;i<=x;++i)b[i]=1,f[i]=l;
        for(int i=x+1;i<l+k;++i){
            if(b[i]) break;
            b[i]=2,f[i]=l;
        }
        a[i]=l;
    }
    for(int i=1;i<n;++i)printf("%d ",a[i]);
    printf("%d\n",a[n]);
	return 0;
}