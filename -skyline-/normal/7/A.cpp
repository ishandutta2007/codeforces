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
int cnt[300],ans=16;
char c[10][10];
int main(){
    for(int _=0;_<256;++_){
        for(int i=0;i<8;++i)if(_&(1<<i))++cnt[_];
    }
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j)scanf(" %c",c[i]+j);
    }
    for(int _=0;_<256;++_){
        for(int __=0;__<256;++__){
            if(cnt[_]+cnt[__]>=ans) continue;
            bool ok=1;
            for(int i=0;i<8;++i){
                for(int j=0;j<8;++j){
                    char C=((_&(1<<i))||(__&(1<<j)))?'B':'W';
                    if(C!=c[i][j])ok=0,i=j=8;
                }
            }
            if(ok)ans=cnt[_]+cnt[__];
        }
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}