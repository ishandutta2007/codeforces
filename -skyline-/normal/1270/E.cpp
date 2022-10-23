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
int n,x[1005],y[1005],ans[1005],k;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
    while(1){
        int o=0;
        for(int i=1;i<=n;++i)if((x[i]-y[i])%2==0)++o;
        if(o==0){
            for(int i=1;i<=n;++i)++x[i];
            o=n;
        }
        if(o==n){
            for(int i=1;i<=n;++i){
                int p=x[i]+y[i],q=x[i]-y[i];
                x[i]=p/2,y[i]=q/2;
            }
            continue;
        }
        for(int i=1;i<=n;++i)if((x[i]-y[i])%2==0)ans[++k]=i;
        break;
    }
    printf("%d\n",k);
    for(int i=1;i<k;++i)printf("%d ",ans[i]);
    printf("%d\n",ans[k]);
    //system("pause");
    return 0;
}