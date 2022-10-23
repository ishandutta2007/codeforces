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
#define eps  0.9999999
#define eps2  0.0000001
//:
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int n,t,ans;
bool ok;
double d[12][12];
void cty(int x,int y,double c){
     d[x][y]+=c;
     if(d[x][y]<1+eps2||x==n) return;
     c=d[x][y]-1;
     d[x][y]=1;
     c/=2;
     cty(x+1,y,c),cty(x+1,y+1,c);
}
int main()
{
    scanf("%d%d",&n,&t);
    while(t--){
               cty(1,1,1);
               if(d[n][1]>eps)t=0;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)if(d[i][j]>eps)ans++;
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}