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
#define X    first
#define Y    second
//:
using namespace std;
pair<pair<int,int>,int> p[300005];
int n,k;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",&p[i].X.X,&p[i].X.Y),p[i].X.Y=-p[i].X.Y,p[i].Y=i;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i){
        p[i].X.Y=-p[i].X.Y;
        if(p[i].X.Y<=p[k].X.Y){
            printf("%d %d\n",p[i].Y,p[k].Y);
            return 0;
        }
        if(p[i].X.Y>p[k].X.Y)k=i;
    }
    printf("-1 -1\n");
//	system("pause");
	return 0;
}