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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,a[100005];
char c[100005];
ll f[100005][4];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        if(c[i]=='h'){
            f[i][0]=f[i-1][0]+a[i];
            f[i][1]=min(f[i-1][0],f[i-1][1]);
            f[i][2]=f[i-1][2];
            f[i][3]=f[i-1][3];
        }
        else if(c[i]=='a'){
            f[i][0]=f[i-1][0];
            f[i][1]=f[i-1][1]+a[i];
            f[i][2]=min(f[i-1][1],f[i-1][2]);
            f[i][3]=f[i-1][3];
        }
        else if(c[i]=='r'){
            f[i][0]=f[i-1][0];
            f[i][1]=f[i-1][1];
            f[i][2]=f[i-1][2]+a[i];
            f[i][3]=min(f[i-1][2],f[i-1][3]);
        }
        else if(c[i]=='d'){
            f[i][0]=f[i-1][0];
            f[i][1]=f[i-1][1];
            f[i][2]=f[i-1][2];
            f[i][3]=f[i-1][3]+a[i];
        }
        else{
            f[i][0]=f[i-1][0];
            f[i][1]=f[i-1][1];
            f[i][2]=f[i-1][2];
            f[i][3]=f[i-1][3];
        }
    }
    printf("%I64d\n",min(min(f[n][0],f[n][1]),min(f[n][2],f[n][3])));
	//system("pause");
	return 0;
}