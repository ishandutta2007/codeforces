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
int n,k;
char c[6][120];
void out(){
    puts("YES");
    for(int i=1;i<=4;++i){
        for(int j=1;j<=n;++j)printf("%c",c[i][j]);
        printf("\n");
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=4;++i){
        for(int j=1;j<=n;++j)c[i][j]='.';
    }
    if(k&1){
        if(k<=n-2){
            int o=(n-k)/2;
            for(int i=1;i<=k;++i)c[2][i+o]='#';
            out();
            return 0;
        }
        for(int i=2;i<=n-1;++i)c[2][i]='#';
        k-=n;
        c[3][2]=c[3][n-1]='#';
        for(int i=0;i<k;++i)c[3][3+i]='#';
        out();
        return 0;
    }
    for(int i=2;i<=k/2+1;++i)c[2][i]=c[3][i]='#';
    out();
	return 0;
}