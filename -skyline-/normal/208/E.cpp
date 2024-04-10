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
int n,p[20][100005],m,in[100005],out[100005],d[100005],sta;
vector<int> v[100005];
vector<int> e[100005];
void ope(int x,int de){
     in[x]=++sta;
     d[x]=de;
     v[de].pb(sta);
     for(int i=2;i<=18;i++)p[i][x]=p[i-1][p[i-1][x]];
     de++;
     for(int i=0;i<e[x].size();i++)ope(e[x][i],de);
     out[x]=++sta;
}
int pa(int x,int k){
     for(int i=18;i;i--)if(k&(1<<(i-1)))x=p[i][x];
     return x;
}
int dtx(int x,int k){
    int l=0,r=v[x].size()-1;
    while(r-l>1){
                 int m=(l+r)>>1;
                 if(v[x][m]>k)r=m;
                 else l=m;
    }
    while(v[x][l]>k&&l>-1)l--;
    while(l<v[x].size()-1&&v[x][l+1]<=k)l++;
    return l+1;
}
int cty(int x,int k){
     return dtx(k,out[x])-dtx(k,in[x]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",p[1]+i),e[p[1][i]].pb(i);
    ope(0,0);
    scanf("%d",&m);
    while(m--){
               int x,y;
               scanf("%d%d",&x,&y);   
               int par=pa(x,y);
               if(!par)printf("0");
               else{
                    printf("%d",cty(par,d[x])-1);
               }
               if(m)printf(" ");
               else printf("\n");
    }
//	system("pause");
	return 0;
}