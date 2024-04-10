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
int n,a,b,ans;
int x[105],y[105];
bool ok(int x,int y,int X,int Y){
     return (x<=X&&y<=Y)||(x<=Y&&y<=X);
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
    for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    if((y[i]<=b&&ok(x[j],y[j],a-x[i],b)))ans=max(ans,x[i]*y[i]+x[j]*y[j]);
                    if((y[i]<=a&&ok(x[j],y[j],a,b-x[i])))ans=max(ans,x[i]*y[i]+x[j]*y[j]);
                    if((x[i]<=b&&ok(x[j],y[j],a-y[i],b)))ans=max(ans,x[i]*y[i]+x[j]*y[j]);
                    if((x[i]<=a&&ok(x[j],y[j],a,b-y[i])))ans=max(ans,x[i]*y[i]+x[j]*y[j]);
            }
    }
    printf("%d\n",ans);
  //  system("pause");
	return 0;
}