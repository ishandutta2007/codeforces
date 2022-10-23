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
//
//
int n,ans,f[200005],a[200005],m;
pair<int,pair<int,int> >p[200005];
int cty(int x){return x==f[x]?x:f[x]=cty(f[x]);}
int main()       
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)f[i]=i;
    for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].Y.X,&p[i].Y.Y,&p[i].X);
    sort(p+1,p+n+1);
    for(int i=n;i;i--){
            if(cty(p[i].Y.X)==cty(p[i].Y.Y)){
                                             if(!a[f[p[i].Y.X]])a[f[p[i].Y.X]]=1,ans+=p[i].X;
            }
            else{
                 if(a[f[p[i].Y.X]]+a[f[p[i].Y.Y]]<=1){
                                                      a[f[p[i].Y.X]]+=a[f[p[i].Y.Y]];
                                                      f[f[p[i].Y.Y]]=f[p[i].Y.X];
                                                      ans+=p[i].X;
                 }
            }
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}