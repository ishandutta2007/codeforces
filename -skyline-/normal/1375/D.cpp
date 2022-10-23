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
int t,n,a[1005],b[1005],c[2005],C;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=n+1;++i)b[i]=0;
        for(int i=1;i<=n;++i)scanf("%d",a+i),++b[a[i]];
        int C=0,p=0,cnt=0;
        while(b[p])++p;
        for(int i=1;i<=n;++i)if(a[i]!=i-1)++cnt;
        while(cnt--){
            if(p==n){
                for(int i=1;i<=n;++i){
                    if(a[i]!=i-1){
                        c[++C]=i;
                        --b[a[i]],++b[n];
                        p=a[i],a[i]=n;
                        break;
                    }
                }
            }
            c[++C]=p+1;
            --b[a[p+1]],++b[p];
            if(a[p+1]<p)swap(p,a[p+1]);
            else a[p+1]=p;
            while(b[p])++p;
        }
        printf("%d\n",C);
        if(!C){
            printf("\n");
            continue;
        }
        for(int i=1;i<C;++i)printf("%d ",c[i]);
        printf("%d\n",c[C]);
    }
    //system("pause");
    return 0;
}