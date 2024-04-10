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
int n,a[5005],cnt[5005],ans[5005],k;
map<int,int> m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        if(!a[i]) continue;
        int t=abs(a[i]);
        for(int j=2;j*j<=t;++j){
            while(t%(j*j)==0)t/=(j*j);
        }
        if(a[i]<0)a[i]=-t;
        else a[i]=t;
        if(m[a[i]])a[i]=m[a[i]];
        else a[i]=m[a[i]]=++k;
    }
    for(int i=1;i<=n;++i){
        memset(cnt,0,sizeof(cnt));
        int r=0;
        for(int j=i;j<=n;++j){
            if(a[j]){
                if(!cnt[a[j]])cnt[a[j]]=1,++r;
            }
            ++ans[r];
        }
    }
    ans[1]+=ans[0];
    for(int i=1;i<n;++i)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
	return 0;
}