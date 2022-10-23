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
int n,q,a[200005],b[100005],c[100005],k;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",a+i),a[0]=max(a[0],a[i]);
    while(a[0]!=a[k+1]){
        ++k;
        b[k]=a[k],c[k]=a[k+1];
        if(a[k]>a[k+1])swap(a[k],a[k+1]);
        a[k+n]=a[k];
    }
    while(q--){
        ll x;
        scanf("%I64d",&x);
        if(x<=k)printf("%d %d\n",b[x],c[x]);
        else{
            x=(x-k)%(n-1);
            if(!x)x=n-1;
            printf("%d %d\n",a[0],a[k+1+x]);
        }
    }
    //system("pause");
    return 0;
}