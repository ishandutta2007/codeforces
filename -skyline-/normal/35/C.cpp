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
int n,m,k;
int x[15],y[15];
int p[15],q[15];
int ans,X=1,Y=1;
int main()
{             
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)scanf("%d%d",x+i,y+i),p[i]=x[i],q[i]=y[i];
    p[k+1]=1,p[k+2]=n,q[k+1]=1,q[k+2]=m;
    sort(p+1,p+k+3);
    sort(q+1,q+k+3);
    for(int i=1;i<=k+2;i++){
            if(p[i]==p[i-1]) continue;
            for(int j=1;j<=m;j++){
                    int res=orz;
                    for(int l=1;l<=k;l++){
                            int o=abs(x[l]-p[i])+abs(y[l]-j);
                            if(o<res)res=o;
                            if(o<=ans) break;
                    }
                    if(res>ans)ans=res,X=p[i],Y=j;
            }
    }
    for(int j=1;j<=k+2;j++){
            if(q[j]==q[j-1]) continue;
            for(int i=1;i<=n;i++){
                    int res=orz;
                    for(int l=1;l<=k;l++){
                            int o=abs(x[l]-i)+abs(y[l]-q[j]);
                            if(o<res)res=o;
                            if(o<=ans) break;
                    }
                    if(res>ans)ans=res,X=i,Y=q[j];
            }
    }
    printf("%d %d\n",X,Y);
//	system("pause");
	return 0;
}