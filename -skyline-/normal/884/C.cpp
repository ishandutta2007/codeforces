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
//
//
int n,p[100005],k,a[100005],b[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=1;i<=n;i++){
            if(b[i]) continue;
            k++;
            int o=i;
            while(!b[o])b[o]=1,a[k]++,o=p[o];
    }
    sort(a+1,a+k+1);
    if(k==1){
             printf("%I64d\n",n*1ll*n);
             return 0;
    }
    ll ans=0;
    a[k-1]+=a[k],k--;
    for(int i=1;i<=k;i++)ans+=a[i]*1ll*a[i];
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}