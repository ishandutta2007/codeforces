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
//:
using namespace std;
char c[1005][1005];
int f[1000005],n,m,nm,e,u[1000005],r[1000005],q[1000005],res[1005][1005],w[1005][1005];
int ope(int x){return x==f[x]?x:f[x]=ope(f[x]);};
bool cty(int i,int j){
     if(c[i][j]=='*') return 0;
     for(int l=1;l<=e;l++)if(r[l]==f[w[i][j]]) return 0;
     return 1;
}
int main()      
{
    scanf("%d%d",&n,&m);
    nm=n*m;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf(" %c",c[i]+j),w[i][j]=++e;
    }
    u[0]=1;
    for(int i=1;i<=nm;i+=10)u[i]=2,u[i+1]=3,u[i+2]=4,u[i+3]=5,u[i+4]=6,u[i+5]=7,u[i+6]=8,u[i+7]=9,u[i+9]=1;
    for(int i=1;i<=n;i++)c[i][0]=c[i][m+1]='*';
    for(int i=1;i<=m;i++)c[0][i]=c[n+1][m]='*';
    for(int i=1;i<=nm;i++)f[i]=i;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(c[i][j]=='*') continue;
                    int k=w[i][j];
                    if(c[i-1][j]=='.')if(ope(k)!=ope(k-m))f[f[k]]=f[k-m];  
                    if(c[i][j-1]=='.')if(ope(k)!=ope(k-1))f[f[k]]=f[k-1];
            }
    }                              
    for(int i=1;i<=nm;i++)f[i]=ope(i);
    for(int i=1;i<=nm;i++)q[f[i]]++;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
            if(c[i][j]=='.') continue;
            e=0;
            if(cty(i-1,j))res[i][j]+=q[f[w[i-1][j]]],r[++e]=f[w[i-1][j]];
            if(cty(i+1,j))res[i][j]+=q[f[w[i+1][j]]],r[++e]=f[w[i+1][j]];
            if(cty(i,j-1))res[i][j]+=q[f[w[i][j-1]]],r[++e]=f[w[i][j-1]];
            if(cty(i,j+1))res[i][j]+=q[f[w[i][j+1]]],r[++e]=f[w[i][j+1]];
            }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(c[i][j]=='.')printf(".");
                    else printf("%d",u[res[i][j]]);
            }
            printf("\n");
    }
   // system("pause");
    return 0;
}