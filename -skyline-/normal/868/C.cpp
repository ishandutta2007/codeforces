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
int f[20],g[20],n,k;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
            int o=0,p=1;
            for(int j=1;j<=k;j++){
                    int x;
                    scanf("%d",&x);
                    o+=p*x;
                    p*=2;
                    if(!x)g[j]++;
            }
            f[o]++;
    }
    if(f[0]){
             puts("YES");
             return 0;
    }
    for(int i=1;i<=k;i++){
            if(g[i]==0){
                        puts("NO");
                        return 0;
            }
    }
    if(k==1||k==2){
             puts("YES");
             return 0;
    }
    if(k==3){
             if(f[1]||f[2]||f[4]) puts("YES");
             else puts("NO");
             return 0;
    }
    if(f[1]||f[2]||f[4]||f[8]){
                               puts("YES");
                               return 0;
    }
    if(f[3]&&f[12]){
                    puts("YES");
                    return 0;
    }    
    if(f[5]&&f[10]){
                    puts("YES");
                    return 0;
    }    
    if(f[9]&&f[6]){
                    puts("YES");
                    return 0;
    }    
    puts("NO");       
	//system("pause");
	return 0;
}