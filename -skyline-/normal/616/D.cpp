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
int n,k,a[500005],ans,ansl,ansr,l,g[1000005],c[1000005],s;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    l=1;
    for(int i=1;i<=n;i++){
            if(i-l>ans){
                        ans=i-l;
                        ansl=l;
                        ansr=i-1;
            }
            g[a[i]]=i,c[a[i]]++;
            if(c[a[i]]==1)s++;
            while(s>k){
                       c[a[l]]--;
                       if(!c[a[l++]])s--;
            }
    }
    if(n+1-l>ans){
                  ansl=l;
                  ansr=n;
    }
    printf("%d %d\n",ansl,ansr);
//	system("pause");
	return 0;
}