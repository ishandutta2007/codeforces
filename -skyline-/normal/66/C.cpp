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
map<string,int> m;
int n;
int p1[10005],p2[10005];
vector<int> v[10005];
bool yes[10005];
int cty(int x){
    if(p1[x]) return p1[x];
    p1[x]=1;
    for(int i=0;i<v[x].size();i++)p1[x]+=cty(v[x][i]);
    return p1[x];
}
int main()
{
    char c;
    string ne="";
    while(c=getchar()){
                       if(c<1) break;
                  if(c!='\n'){
                              ne+=c;
                              continue;
                  }                   
                  string ol="",ol2="";
                  int p=0,t=0;
                  for(int i=0;i<ne.size();i++){
                          ol+=ne[i];
                          if(ne[i]!=92) continue;
                          p++;
                          int mol,mol2=m[ol2];
                          if(m[ol])mol=m[ol];
                          else mol=m[ol]=++n,yes[n]=ol.size()>3;
                          if(!t){
                                 t=i;
                                 ol2=ol;
                                 continue;
                          }
                          if(p==2)p2[mol]++;
                          bool b=1;
                          for(int i=0;i<v[mol2].size();i++)if(v[mol2][i]==mol)b=0,i=10000;
                          if(b)v[mol2].pb(mol);
                          for(int j=t+1;j<=i;j++)ol2+=ne[j];
                          t=i;
                  }
                  ne="";
    }
    for(int i=1;i<=n;i++)cty(i);
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)ans1=max(ans1,yes[i]*p1[i]),ans2=max(ans2,p2[i]);
    printf("%d %d\n",ans1-1,ans2);
  //	system("pause");
	return 0;
}