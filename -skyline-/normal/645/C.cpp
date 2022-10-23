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
//I prefer being hacked than being FST
using namespace std;
int n,k,a[100005],b[100005];
bool ok(int x){
     for(int i=1;i<=n;i++){
             if(!b[i]) continue;
             int l=max(i-x-1,0),r=min(n,i+x);
             if(a[r]-a[l]>k) return 1;
     }
     return 0;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%1d",a+i),a[i]^=1,b[i]=a[i],a[i]+=a[i-1];
    int l=1,r=n-1;
    while(r-l>1){
                 int m=(l+r)>>1;
                 if(ok(m))r=m;
                 else l=m;
    }
    while(ok(l-1))l--;
    while(!ok(l))l++;
    printf("%d\n",l);
//	system("pause");
	return 0;
}