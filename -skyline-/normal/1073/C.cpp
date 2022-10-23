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
int n,lx[200005],ly[200005],x,y,rx[200005],ry[200005],ans;
char c[200005];
bool ok(int l,int r){
    if(l>=r) return 0;
    int X=abs(x-lx[l]-rx[r]),Y=abs(y-ly[l]-ry[r]);
    return X+Y<=r-l-1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf(" %c",c+i);
    scanf("%d%d",&x,&y);
    int O=abs(x)+abs(y);
    if(O>n||((O-n)&1)){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;++i){
        lx[i]=lx[i-1],ly[i]=ly[i-1];
        if(c[i]=='U')++ly[i];
        else if(c[i]=='D')--ly[i];
        else if(c[i]=='L')--lx[i];
        else ++lx[i];
    }
    for(int i=n;i;--i){
        rx[i]=rx[i+1],ry[i]=ry[i+1];
        if(c[i]=='U')++ry[i];
        else if(c[i]=='D')--ry[i];
        else if(c[i]=='L')--rx[i];
        else ++rx[i];
    }
    ans=n;
    int l=0;
    for(int i=0;i<=n;++i){
        while(l<=n+1&&!ok(i,l))++l;
        if(l<=n+1)ans=min(ans,l-i-1);
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}