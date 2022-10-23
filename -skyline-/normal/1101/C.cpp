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
using namespace std;
int T,n,x[100005],y[100005],f1[100005],f2[100005],id[200005];
pair<int,int> p[100005],q[100005];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%d",x+i,y+i);
            f1[i]=f2[i]=1;
            p[i]=mp(x[i],i),q[i]=mp(y[i],i);
            id[i]=x[i],id[n+i]=y[i];
        }
        sort(p+1,p+n+1);
        sort(q+1,q+n+1);
        sort(id+1,id+n*2+1);
        int l1=1,l2=1;
        for(int i=1;i<=n*2;++i){
            if(i>1&&id[i]==id[i-1]) continue;
            while(l1<=n&&p[l1].X==id[i])f1[p[l1].Y]=2,++l1;
            while(l2<=n&&q[l2].X==id[i])f2[q[l2].Y]=2,++l2;
            if(l1==l2) break;
        }
        if(l1<=n){
            for(int i=1;i<n;++i)printf("%d ",f1[i]);
            printf("%d\n",f1[n]);
        }
        else{
            printf("-1\n");
        }
    }
  //	system("pause");
	return 0;
}