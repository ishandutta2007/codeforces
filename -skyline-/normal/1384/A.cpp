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
int t,n,a[105];
char c[105][55];
int main(){
    scanf("%d",&t);
    for(int i=1;i<=50;++i)c[1][i]='a';
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",a+i);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=a[i];++j)c[i+1][j]=c[i][j];
            for(int j=a[i]+1;j<=50;++j)c[i+1][j]=195-c[i][j];
        }
        for(int i=1;i<=n+1;++i){
            for(int j=1;j<=50;++j)printf("%c",c[i][j]);
            printf("\n");
        }
    }
    //system("pause");
    return 0;
}