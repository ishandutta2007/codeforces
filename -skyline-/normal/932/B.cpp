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
int f[1000005],g[1000005],s[1000005][10];
int main(){
    for(int i=1;i<=1000000;i++){
        int t=i;
        f[i]=1;
        while(t){
            if(t%10)f[i]*=(t%10);
            t/=10;
        }
    }
    for(int i=1;i<=9;i++)g[i]=i;
    for(int i=10;i<=1000000;i++)g[i]=g[f[i]];
    for(int i=1;i<=1000000;i++){
        for(int j=1;j<=9;j++)s[i][j]=s[i-1][j];
        s[i][g[i]]++;
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",s[r][k]-s[l-1][k]);
    }
//	system("pause");
	return 0;
}