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
int n,m,a[2505][2505],ans;
int main()
{
    scanf("%d%d",&n,&m); 
    ans=n*m;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf("%1d",a[i]+j),a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
    for(int k=2;k<=n||k<=m;k++){
            int res=0;
            for(int i=0;i<n;i+=k){
                    for(int j=0;j<m;j+=k){
                            int o=a[i][j]-a[min(n,i+k)][j]-a[i][min(m,j+k)]+a[min(n,i+k)][min(m,j+k)];
                            o=min(o,k*k-o);
                            res+=o;
                    }
            }
            ans=min(ans,res);
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}