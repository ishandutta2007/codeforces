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
using namespace std;
int n,a[500005],ans[500005];
ll s[500005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    int o=0;
    for(int i=1;i<=n;++i){
        ll L=s[n]-s[n-i];
        ll R=i*(i-1ll);
        while(o<n&&a[o+1]<i)++o;
        int O=min(n-i,o);
        R+=s[O]+i*1ll*(n-i-O);
        ll b=a[n-i+1];
        ll D=L-R;
        if(D<=i&&D<=b){
            ++ans[max(0ll,D)];
            --ans[b+1];
        }
        L-=b;
        R+=min(b,i*1ll);
        D=R-L;
        if(D>b){
            ++ans[b+1];
            --ans[min(D,n*1ll)+1];
        }
    }
    bool ok=0;
    o=0;
    for(int i=0;i<=n;++i){
        o+=ans[i];
        if(o==n&&(s[n]+i)%2==0)printf("%d ",i),ok=1;
    }
    if(!ok)printf("-1\n");
//	system("pause");
	return 0;
}