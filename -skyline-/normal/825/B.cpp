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
int a[15][15];
bool ok(){
     for(int i=1;i<=10;i++){
             for(int j=1;j<=6;j++)if(a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]+a[i][j+4]==10) return 1;
     }
     for(int i=1;i<=6;i++){
             for(int j=1;j<=10;j++)if(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]+a[i+4][j]==10) return 1;
     }  
     for(int i=1;i<=6;i++){
             for(int j=1;j<=6;j++)if(a[i][j]+a[i+1][j+1]+a[i+2][j+2]+a[i+3][j+3]+a[i+4][j+4]==10) return 1;
     }
     for(int i=5;i<=10;i++){
             for(int j=1;j<=6;j++)if(a[i][j]+a[i-1][j+1]+a[i-2][j+2]+a[i-3][j+3]+a[i-4][j+4]==10) return 1;
     }
     return 0;
}
int main()
{
    for(int i=1;i<=10;i++){
            for(int j=1;j<=10;j++){
                    char c;
                    scanf(" %c",&c);
                    if(c=='O')a[i][j]=1;
                    else if(c=='X')a[i][j]=2;
            }
    }
    for(int i=1;i<=10;i++){
            for(int j=1;j<=10;j++){
                    if(a[i][j]) continue;
                    a[i][j]=2;
                    if(ok()){
                             puts("YES");
                             return 0;
                    }
                    a[i][j]=0;
            }
    }
    puts("NO");
// 	system("pause");
	return 0;
}