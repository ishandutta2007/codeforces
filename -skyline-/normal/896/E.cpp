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
//:
using namespace std;
int n,m,a[100005];
int b[10],B;
int get(){
    register char c=getchar();
    register int o=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))o=o*10+c-48,c=getchar();
    return o;
}
void out(int x){
     if(!x){
            puts("0");
            return;
     }
     while(x)b[++B]=x%10,x/=10;
     while(B)putchar(b[B--]+48);
     putchar('\n');
}
int main()
{
    n=get(),m=get();
    for(register int i=1;i<=n;++i)a[i]=get();
    while(m--){
               register int t=get(),l=get(),r=get()+1,x=get();
               r-=l;
               register int* A=a+l;
               if(t==1){
                        for(register int i=0;i<r;++i)A[i]-=A[i]>x?x:0;
               }
               else{
                    register int ans=0;
                    for(register int i=0;i<r;++i)ans+=A[i]==x;
                    out(ans);
               }
    }
//	system("pause");
	return 0;
}