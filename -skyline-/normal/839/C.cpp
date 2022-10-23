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
int n;
vector<int> v[100005];
double d[100005];
void cty(int x,int p){
     double o=0,cnt=0;
     for(int i=0;i<v[x].size();i++){
             if(v[x][i]==p) continue;
             cty(v[x][i],x);
             o+=d[v[x][i]];
             cnt+=1.0;
     }
     if(cnt>0)d[x]=o/cnt+1.0;
     else d[x]=1.0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y),v[y].pb(x);
    }
    cty(1,0);
    printf("%.10lf\n",d[1]-1.0);
	//system("pause");
	return 0;
}