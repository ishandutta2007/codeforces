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
int n,m,k=-1;
string s,t;
int main(){
    cin>>n>>m>>s>>t;
    if(n>m+1){
        puts("NO");
        return 0;
    }
    for(int i=0;i<n;++i)if(s[i]=='*')k=i;
    if(k==-1){
        if(s==t)puts("YES");
        else puts("NO");
        return 0;
    }
    for(int i=0;i<k;++i){
        if(s[i]!=t[i]){
            puts("NO");
            return 0;
        }
    }
    for(int i=k+1;i<n;++i){
        if(s[i]!=t[i-n+m]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
//	system("pause");
	return 0;
}