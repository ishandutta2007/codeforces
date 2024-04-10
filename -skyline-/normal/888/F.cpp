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
#define orz  1000000007ll
//:
using namespace std;
int g[505][505],n;
ll f[505][505],ans[505][505];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)scanf("%d",g[i]+j);
    }
    for(int i=0;i<n;i++)f[i][i]=1,ans[i][i]=1;
    for(int l=1;l<n;l++){
            for(int i=0;i<n;i++){
                    int j=(i+l)%n;   
                    if(g[i][j]){
                        for(int k=i;k!=j;k=(k+1)%n)f[i][j]+=ans[i][k]*ans[(k+1)%n][j]%orz;
                        f[i][j]%=orz;
                    }
                    for(int k=i;k!=j;k=(k+1)%n)ans[i][j]+=f[i][(k+1)%n]*ans[(k+1)%n][j]%orz;
                    ans[i][j]%=orz;
                    
            }
    }
    printf("%I64d\n",ans[0][n-1]);
//	system("pause");
	return 0;
}