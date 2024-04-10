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
int n,l[100005],s[100005],m;
vector<int> v[100005],e[100005];
bool ok=1;
bool u[100005];
void cty(int x){     
     u[x]=1;
     if(s[x]==2) ok=0;
     if(!ok) return;     
     s[x]=1;
     for(int i=0;i<e[x].size();i++)if(!u[e[x][i]])cty(e[x][i]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
            scanf("%d",l+i);
            for(int j=1;j<=l[i];j++){
                    int x;
                    scanf("%d",&x);
                    v[i].pb(x);
            }
    }
    for(int i=1;i<n;i++){
            int o=-1;
            for(int j=0;j<min(l[i],l[i+1]);j++){
                    if(v[i][j]!=v[i+1][j]){
                                           o=j;
                                           break;
                    }
            }
            if(o==-1){
                      if(l[i]>l[i+1]){
                                      ok=0;
                                      break;
                      }
                      continue;
            }
            if(v[i][o]>v[i+1][o]){
                                  if(s[v[i][o]]==2||s[v[i+1][o]]==1){
                                                                     ok=0;
                                                                     break;
                                  }
                                  s[v[i][o]]=1;
                                  s[v[i+1][o]]=2;
                                  continue;
            }
            e[v[i+1][o]].pb(v[i][o]);
    }
    if(ok){
           for(int i=1;i<=m;i++){
                   if(!u[i]&&s[i]==1) cty(i);
           }
    }                             
    if(!ok)puts("No");
    else{
         puts("Yes");
         int k=0;
         for(int i=1;i<=m;i++)if(s[i]==1)k++;
         printf("%d\n",k);
         for(int i=1;i<=m;i++)if(s[i]==1)printf("%d ",i);
    }        
//	system("pause");
	return 0;
}