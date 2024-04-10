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
//
int n,c[100005],u[100005];
vector<int> v[100005],V;
void cty(int x,int k){
     if(u[x]) return;
     if(c[x]!=k){
                 V.pb(x);
                 return;
     }
     u[x]=1;
     for(int i=0;i<v[x].size();i++)cty(v[x][i],k);
}
int dtx(int s){
    V.clear();
    memset(u,0,sizeof(u)) ;
    cty(s,c[s]);
    if(V.size()>1) return 0;
    if(V.size()==0) return s;
    int r=V[0]; 
    u[r]=1;
    for(int i=0;i<v[r].size();i++){
            cty(v[r][i],c[v[r][i]]);
    }
    for(int i=1;i<=n;i++)if(!u[i]) return 0;
    return r;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
    }
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    int k=dtx(1);
    if(k)printf("YES\n%d\n",k);
    else{
         for(int i=1;i<=n;i++){
                 if(c[i]!=c[1])k=dtx(i),i=n+1;
         }
         if(k)printf("YES\n%d\n",k);
         else puts("NO");
    }
	//system("pause");
	return 0;
}