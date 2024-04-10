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
int n,a[1005],b[1005],x[1000005],y[1000005],k;
pair<int,int> p[1005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i),p[i]=mp(a[i],i);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i)a[p[i].second]=i;
    for(int i=1;i<=n;++i)b[a[i]]=i;
    for(int i=1;i<=n;++i){
        for(int j=n;j>b[i];--j){
            if(a[j]<i){
                ++k;
                x[k]=b[i],y[k]=j;
            }
        }
    }
    printf("%d\n",k);
    for(int i=1;i<=k;++i)printf("%d %d\n",x[i],y[i]);
    //system("pause");
    return 0;
}