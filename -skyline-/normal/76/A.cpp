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
#define orz  1000000007ll
#define X    first
#define Y    second
//:
using namespace std;
//
//
int n,m,A,B,f[405],a[405],s;
ll ans;
pair<pair<int,int>,pair<int,int> >p[50005];
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
int main()      
{
    scanf("%d%d%d%d",&n,&m,&A,&B);
    for(int i=1;i<=m;i++)scanf("%d%d%d%d",&p[i].Y.X,&p[i].Y.Y,&p[i].X.X,&p[i].X.Y);
    sort(p+1,p+m+1);
    ans=-1;
    for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)f[j]=j;
            a[++s]=i;
            for(int j=1;j<s;j++){
                    if(p[i].X.Y<p[a[j]].X.Y){
                                             for(int k=s;k>j;k--)a[k]=a[k-1];
                                             a[j]=i;
                                             break;
                    }
            }
            int o=0;
            for(int j=1;j<=s;j++){
                    if(get(p[a[j]].Y.X)!=get(p[a[j]].Y.Y)){
                                                           a[++o]=a[j];
                                                           f[f[p[a[j]].Y.X]]=f[p[a[j]].Y.Y];
                    }
            }
            s=o;
            if(o==n-1){
                       ll ans2=A*1ll*p[i].X.X+B*1ll*p[a[o]].X.Y;
                       if(ans==-1||ans>ans2)ans=ans2;
            }
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}