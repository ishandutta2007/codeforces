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
int n,a[100005],k;
int cty(int l,int r,int x,int o){
    if(o==1||l==r){
             for(int i=l;i<=r;i++)a[i]=x-l+i;
             return 1;
    }
    int m=(l+r-1)>>1;
    int p=cty(l,m,x-m+r,o-2);
    int q=cty(m+1,r,x,o-p-1);
    return p+q+1;
} 
int main()
{
    scanf("%d%d",&n,&k);
    if(k%2==0){
               puts("-1");
               return 0;
    }
    int o=cty(1,n,1,k);
    if(o!=k)puts("-1");
    else{
         for(int i=1;i<n;i++)printf("%d ",a[i]);
         printf("%d\n",a[n]);
    }
//	system("pause");
	return 0;
}