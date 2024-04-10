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
bitset<100005> b[26],B,e;
int n,a[100005],q,A[100005];
int main(){
    char c=getchar();
    while(c>96)e[n]=1,a[++n]=c-97,c=getchar(),b[a[n]][n]=1;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int x;
            scanf("%d %c",&x,&c);
            b[a[x]][x]=0;
            a[x]=c-97;
            b[a[x]][x]=1;
        }
        else{
            int l,r,k=0;
            scanf("%d%d %c",&l,&r,&c);
            while(c>96)A[++k]=c-97,c=getchar();
            if(r-l+1<k){
                printf("0\n");
                continue;
            }
            B=e;
            for(int i=1;i<=k;++i)B&=(b[A[i]]>>(l+i-1));
            printf("%d\n",B.count()-(B>>(r-l+2-k)).count());
        }
    }
    //system("pause");
    return 0;
}