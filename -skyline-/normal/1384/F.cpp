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
int n,m,a[255][255],r[63000],c[63000],x,y,ans[255][255],qx[63000],qy[63000],ql,qr;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)scanf("%d",a[i]+j);
    }
    for(int i=1;i<=n;++i){
        int x=0;
        for(int j=1;j<=m;++j)x=max(x,a[i][j]);
        r[x]=1;
    }
    for(int j=1;j<=m;++j){
        int x=0;
        for(int i=1;i<=n;++i)x=max(x,a[i][j]);
        c[x]=1;
    }
    for(int i=n*m;i;--i){
        if(r[i]&&c[i]){
            ++x,++y;
            ans[x][y]=i;
            for(int j=y-1;j;--j)++qr,qx[qr]=x,qy[qr]=j;
            for(int j=x-1;j;--j)++qr,qx[qr]=j,qy[qr]=y;
        }
        else if(r[i]){
            ++x;
            ans[x][y]=i;
            for(int j=y-1;j;--j)++qr,qx[qr]=x,qy[qr]=j;
        }
        else if(c[i]){
            ++y;
            ans[x][y]=i;
            for(int j=x-1;j;--j)++qr,qx[qr]=j,qy[qr]=y;
        }
        else{
            ++ql;
            ans[qx[ql]][qy[ql]]=i;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<m;++j)printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][m]);
    }
    //system("pause");
    return 0;
}