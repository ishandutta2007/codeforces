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
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
vector<int> v[100005];
int n,m,q,ans,res[100005],f[100005],x[100005],y[100005],t[100005],p[100005];
bool b[1005][1005],r[1005],d[100005];
void cty1(int x,int y){
     if(!r[x]){
               if(!b[x][y])b[x][y]=1,ans++,f[x]++;
     }
     else if(r[x]){
          if(b[x][y]) b[x][y]=0,ans++,f[x]++;
     }
}
void cty2(int x,int y){
     if(!r[x]){
               if(b[x][y])b[x][y]=0,ans--,f[x]--;
     }
     else if(r[x]){
          if(!b[x][y]) b[x][y]=1,ans--,f[x]--;
     }
}
void cty3(int x){
     r[x]^=1;
     ans-=f[x];
     f[x]=m-f[x];
     ans+=f[x];
}
void cty(int k){
     if(k){
           int anss=ans;
           if(t[k]==1)cty1(x[k],y[k]);
           else if(t[k]==2)cty2(x[k],y[k]);
           else if(t[k]==3)cty3(x[k]);
           if(t[k]==3||ans!=anss)d[k]=1;
     }
     res[k]=ans;
     for(int i=0;i<v[k].size();i++)cty(v[k][i]);
     if(k&&d[k]){
           if(t[k]==1)cty2(x[k],y[k]);
           else if(t[k]==2)cty1(x[k],y[k]);
           else if(t[k]==3)cty3(x[k]);
     }
}        
             
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++){
            scanf("%d",t+i);
            if(t[i]==1)scanf("%d%d",x+i,y+i);
            if(t[i]==2)scanf("%d%d",x+i,y+i);
            if(t[i]==3)scanf("%d",x+i);
            if(t[i]==4)scanf("%d",x+i);
            if(t[i]==4)v[x[i]].pb(i),p[i]=x[i];
            else v[i-1].pb(i),p[i]=i-1;
    }
    cty(0);
    for(int i=1;i<=q;i++)printf("%d\n",res[i]);
//	system("pause");
	return 0;
}