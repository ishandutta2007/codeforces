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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,d,m,a[100005],k,cnt;
ll s[100005],ans;
int main(){
    scanf("%d%d%d",&n,&d,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        if(a[i]>m)++cnt;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    ans=s[n-cnt];
    for(int i=1;i<=cnt;++i){
        if((i-1ll)*(d+1ll)+1ll>n) break;
        if(i*(d+1ll)<cnt) continue;
        ll res;
        if((i-1ll)*(d+1ll)+1ll<cnt)res=s[n]-s[n-i]+s[n-cnt];
        else res=s[n-cnt]-s[(i-1)*d-cnt+i]+s[n]-s[n-i];
        if(res>ans)ans=res;
    }
    printf("%I64d\n",ans);
    //system("pause");
    return 0;
}