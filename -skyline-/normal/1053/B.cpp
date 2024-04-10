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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,a[300005],s[300005],cnt[300005][2];
ll ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        ll o;
        scanf("%I64d",&o);
        for(int j=0;j<63;++j)if((o>>j)&1ll)++a[i];
    }
    cnt[0][0]=1;
    for(int i=1;i<=n;++i){
        s[i]=s[i-1]+a[i];
        cnt[i][0]=cnt[i-1][0],cnt[i][1]=cnt[i-1][1];
        int _=(s[i]&1);
        ++cnt[i][_];
        int l=max(1,i-65),o=a[i];
        for(int j=i-1;j>=l;--j){
            o=max(o,a[j]);
            if((s[j-1]&1)==_&&s[i]-s[j-1]>=o*2)++ans;
        }
        if(l>1)ans+=cnt[l-2][_];
    }
    printf("%I64d\n",ans); 
//	system("pause");
	return 0;
}