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
int n,a[2005],f[2005][2005][2],g[2005][2005][2],ans,h[2005][2005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j]==1)f[i][j][0]=f[i][j-1][0]+1;
            else f[i][j][0]=f[i][j-1][0];
            g[i][j][0]=f[i][j][0];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[i][j][1]=max(f[i][j-1][0],f[i][j-1][1]);
            if(a[j]==2)f[i][j][1]++;
        }
    }
    for(int j=n;j>0;j--){
        for(int i=j;i>0;i--){
            g[i][j][1]=max(g[i+1][j][1],g[i+1][j][0]);
            if(a[i]==2)g[i][j][1]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            h[i][j]=h[i][j-1];
            if(a[j]==2)h[i][j]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans=max(ans,f[1][i-1][0]+g[i][j][0]+f[j+1][n][0]);
            ans=max(ans,f[1][i-1][0]+g[i][j][0]+f[j+1][n][1]);
            ans=max(ans,f[1][i-1][0]+g[i][j][1]+h[j+1][n]);
            ans=max(ans,f[1][i-1][1]+h[i][n]);
        }
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}