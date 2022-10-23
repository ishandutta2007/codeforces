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
int T,n,a[200005],cnt[200005],C;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)cnt[i]=0;
        C=0;
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        int l=0,ans=n+1;
        for(int i=1;i<n;++i){
            while(l<=i){
                ++l;
                if(cnt[a[l]])C=1;
                ++cnt[a[l]];
            }
            while(!C&&l<n){
                ++l;
                if(cnt[a[l]])C=1;
                ++cnt[a[l]];
            }
            if(C)ans=min(ans,l-i+1);
            --cnt[a[i]];
            if(cnt[a[i]])C=0;
        }
        if(ans>n)printf("-1\n");
        else printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}