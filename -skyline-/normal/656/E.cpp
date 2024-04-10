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
//:
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int n,ans,a[15][15],k,i,j,rev;
int cty(int x,int y){
     scanf("%d",a[x]+y);
     y==n?y=1,x++:y++;
     x<=n?rev=cty(x,y):x=x;  
     return 0;
}

int cty0(int x,int y){
     ans=max(ans,a[x][y]);
     y==n?y=1,x++:y++;
     x<=n?rev=cty0(x,y):x=x; 
     return 0;
}  
int cty3(){                                      
     a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
     j++;
     j<=n?rev=cty3():j=j;
     return 0;
}
int cty2(){
     j=1;
     rev=cty3();
     i++;
     i<=n?rev=cty2():i=i;  
     return 0;
}
int cty1(){
     i=1;
     rev=cty2();
     k++;
     k<=n?rev=cty1():k=k;  
     return 0;
}
int main()
{
    scanf("%d",&n);
    cty(1,1);
    k=1;
    cty1();     
    cty0(1,1);
    printf("%d\n",ans);
//	system("pause");
	return 0;
}