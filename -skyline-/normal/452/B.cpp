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
//:
using namespace std;
int n,m,a1,a2,a3,a4;
double d;
vector<int> x,y;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)if(i+j<3||i+m-j<3||n-i+j<3||n-i+m-j<3)x.push_back(i),y.push_back(j);
    }
    for(int i=0;i<x.size();i++){
            for(int j=0;j<x.size();j++){
                    if(i==j) continue;
                    for(int k=0;k<x.size();k++){
                            if(k==i||k==j) continue;
                            for(int l=0;l<x.size();l++){
                                    if(l==i||l==j||l==k) continue;
                                    double s=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))+sqrt((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]))+sqrt((x[k]-x[l])*(x[k]-x[l])+(y[k]-y[l])*(y[k]-y[l]));
                                    if(s>d) d=s,a1=i,a2=j,a3=k,a4=l;
                            }
                    }
            }
    }
    printf("%d %d\n%d %d\n%d %d\n%d %d\n",x[a1],y[a1],x[a2],y[a2],x[a3],y[a3],x[a4],y[a4]);                                        
	//system("pause");
	return 0;
}