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
#define orz  998244353
using namespace std;
int n,k,a[1005],f[1005][1005],ans;
void add(int &x,int y){
    x+=y;
    if(x>=orz)x-=orz;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    int _=(a[n]-a[1])/(k-1);
    for(int i=0;i<=n;++i)f[i][0]=1;
    for(int i=1;i<=_;++i){
        int l=0;
        for(int r=1;r<=n;++r){
            while(a[r]-a[l+1]>=i)++l;
            for(int j=1;j<=k;++j){
                f[r][j]=f[l][j-1]+f[r-1][j];
                if(f[r][j]>=orz)f[r][j]-=orz;
            }
        }
        add(ans,f[n][k]);
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}