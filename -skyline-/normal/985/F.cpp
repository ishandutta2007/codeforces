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
#define M    1000000007ll
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int n,m,a[200005],b[200005],x[200005],y[200005],z[200005],ans[200005],ap[200005][26],hax[200005][26],hay[200005][26],f[200005];
int get(int l,int r){
    return (int)(((f[r]-f[l-1]*1ll*b[r-l+1])%M+M)%M);
}
int main(){
    b[0]=1;
    for(int i=1;i<=200000;++i)b[i]=b[i-1]*2%orz;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        char c;
        scanf(" %c",&c);
        a[i]=c-97;
    }
    for(int i=1;i<=m;++i)scanf("%d%d%d",x+i,y+i,z+i),ans[i]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<26;++j)ap[i][j]=ap[i-1][j];
        ap[i][a[i]]=i;
    }
    for(int c=0;c<26;++c){
        for(int i=1;i<=n;++i){
            if(a[i]==c)f[i]=(f[i-1]*2+1)%orz;
            else f[i]=f[i-1]*2%orz;
        }
        for(int i=1;i<=m;++i){
            if(ap[x[i]+z[i]-1][c]<x[i])hax[i][c]=-1;
            else hax[i][c]=get(x[i],x[i]+z[i]-1);
            if(ap[y[i]+z[i]-1][c]<y[i])hay[i][c]=-1;
            else hay[i][c]=get(y[i],y[i]+z[i]-1);
        }
    }
    for(int i=1;i<=m;++i){
        for(int c=0;c<26;++c){
            if(ap[x[i]+z[i]-1][c]<x[i]) continue;
            int C=a[ap[x[i]+z[i]-1][c]-x[i]+y[i]];
            if(hax[i][c]!=hay[i][C])ans[i]=0,c=26;
        }
        if(ans[i])puts("YES");
        else puts("NO");
    }
//	system("pause");
	return 0;
}