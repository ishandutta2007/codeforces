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
int n;
ll l[100005],s,g,e,ans;
bool es,ew;
char c[100005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%I64d",l+i);
    for(int i=1;i<=n;++i)scanf(" %c",c+i);
    for(int i=1;i<=n;++i){
        if(c[i]=='W')es=1,s+=l[i]*2ll;
        else if(c[i]=='G')ew=1,g+=l[i]*2ll;
        ans+=l[i];
        e-=l[i];
        if(e<0){
            if(s+e>=0)ans-=e,s+=e,e=0;
            else ans+=s,e+=s,s=0;
            if(g+e>=0)ans-=e*2ll,g+=e,e=0;
            else ans+=g*2ll,e+=g,g=0;
            if(e<0&&es)ans-=e*3ll,e=0;
            if(e<0&&ew)ans-=e*5ll,e=0;
        }
    }
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}