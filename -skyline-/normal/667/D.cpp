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
//I prefer being hacked than being FST
using namespace std;
int n,m,xd[3005],xz[3005],xx[3005],yd[3005],yz[3005],yx[3005],xd2[3005],xz2[3005],xx2[3005],yd2[3005],yz2[3005],yx2[3005],d[3005],q[5005],qs,qe,ans,ans1,ans2,ans3,ans4;
vector<int> v[3005],v2[3005];
void cty(int a,int b,int c,int d,int e){if(e>ans&&a&&d&&a!=c&&b!=d&&a!=d)ans=e,ans1=a,ans2=b,ans3=c,ans4=d;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int uu,vv;
            scanf("%d%d",&uu,&vv);
            v[uu].pb(vv),v2[vv].pb(uu);
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)d[j]=orz;
            d[i]=0,qs=1,qe=0,q[1]=i;
            while(qs!=qe){
                          int k=q[++qe];
                          if(k!=i){
                                   if(d[k]>xd[i])xx[i]=xz[i],xz[i]=xd[i],xd[i]=d[k],yx[i]=yz[i],yz[i]=yd[i],yd[i]=k;
                                   else if(d[k]>xz[i])xx[i]=xz[i],xz[i]=d[k],yx[i]=yz[i],yz[i]=k;
                                   else if(d[k]>xx[i])xx[i]=d[k],yx[i]=k;
                          }
                          for(int j=0;j<v[k].size();j++)if(d[v[k][j]]==orz)d[v[k][j]]=d[k]+1,q[++qs]=v[k][j];
            }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)d[j]=orz;
            d[i]=0,qs=1,qe=0,q[1]=i;
            while(qs!=qe){
                          int k=q[++qe];
                          if(k!=i){
                                   if(d[k]>xd2[i])xx2[i]=xz2[i],xz2[i]=xd2[i],xd2[i]=d[k],yx2[i]=yz2[i],yz2[i]=yd2[i],yd2[i]=k;
                                   else if(d[k]>xz2[i])xx2[i]=xz2[i],xz2[i]=d[k],yx2[i]=yz2[i],yz2[i]=k;
                                   else if(d[k]>xx2[i])xx2[i]=d[k],yx2[i]=k;
                          }
                          for(int j=0;j<v2[k].size();j++)if(d[v2[k][j]]==orz)d[v2[k][j]]=d[k]+1,q[++qs]=v2[k][j];
            }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)d[j]=orz;
            d[i]=0,qs=1,qe=0,q[1]=i;
            while(qs!=qe){
                          int k=q[++qe];
                          for(int j=0;j<v[k].size();j++)if(d[v[k][j]]==orz)d[v[k][j]]=d[k]+1,q[++qs]=v[k][j];
            }
            for(int j=1;j<=n;j++){
                    if(i==j||d[j]==orz) continue;
                    cty(yd2[i],i,j,yd[j],d[j]+xd2[i]+xd[j]);
                    cty(yz2[i],i,j,yd[j],d[j]+xz2[i]+xd[j]);
                    cty(yx2[i],i,j,yd[j],d[j]+xx2[i]+xd[j]);
                    cty(yd2[i],i,j,yz[j],d[j]+xd2[i]+xz[j]);
                    cty(yz2[i],i,j,yz[j],d[j]+xz2[i]+xz[j]);
                    cty(yx2[i],i,j,yz[j],d[j]+xx2[i]+xz[j]);
                    cty(yd2[i],i,j,yx[j],d[j]+xd2[i]+xx[j]);
                    cty(yz2[i],i,j,yx[j],d[j]+xz2[i]+xx[j]);
                    cty(yx2[i],i,j,yx[j],d[j]+xx2[i]+xx[j]);
            }
    }
    printf("%d %d %d %d\n",ans1,ans2,ans3,ans4);
    //system("pause");
	return 0;
}