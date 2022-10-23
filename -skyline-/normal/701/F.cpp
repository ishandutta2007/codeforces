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
int n,m,s,t,q[1005],qs,b[1005],w[30005],x[30005],y[30005];
int stp,o[1005],p[1005],q2[30005],q2s,cnt[1005][1005];
pair<int,int> ans,res;
vector<int> v[1005],e[1005];
bool ope(int k){         
     b[k]=1;
     if(k==t) return 1;
     for(int i=0;i<v[k].size();i++){
             if(!b[v[k][i]]&&ope(v[k][i])){
                                           q[++qs]=e[k][i];
                                           return 1;
             }
     }
     return 0;
}
bool dtx(int k,int pa){
     p[k]=o[k];
     bool ret=k==t;
     for(int i=0;i<v[k].size();i++){
             if(e[k][i]==stp||v[k][i]==pa) continue;
             if(o[v[k][i]]) p[k]=min(p[k],o[v[k][i]]);
             else{
                  o[v[k][i]]=o[k]+1;
                  if(dtx(v[k][i],k))ret=1,q2[++q2s]=e[k][i];
                  p[k]=min(p[k],p[v[k][i]]);
             }
     }
     return ret;
}
                            
void cty(){
     q2s=0;
     memset(o,0,sizeof(o));
     o[s]=1;
     dtx(s,-1);
     if(!o[t]){
               if(mp(w[stp],1)<ans){
                                    ans=mp(w[stp],1);
                                    res=mp(stp,0);
               }
               return;
     }
     for(int i=1;i<=q2s;i++){
             int k=q2[i];
             if(cnt[x[k]][y[k]]>1) continue;
             if(p[x[k]]<=o[y[k]]&&p[y[k]]<=o[x[k]]) continue;
             if(mp(w[stp]+w[k],2)<ans){
                                  ans=mp(w[stp]+w[k],2);
                                  res=mp(stp,k);
             }
     }
}
int main()                             
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
            int X,Y,W;
            scanf("%d%d%d",&X,&Y,&W);
            v[X].pb(Y),v[Y].pb(X);
            e[X].pb(i),e[Y].pb(i);
            w[i]=W,x[i]=X,y[i]=Y; 
            cnt[X][Y]++,cnt[Y][X]++;
    }
    ope(s);
    if(!b[t]){
              printf("0\n0\n\n");
              return 0;
    }
    ans=mp(orz+orz,3);
    for(int i=1;i<=qs;i++){
            stp=q[i];
            cnt[x[stp]][y[stp]]--,cnt[y[stp]][x[stp]]--;
            cty();
            cnt[x[stp]][y[stp]]++,cnt[y[stp]][x[stp]]++;
    }
    if(ans.second==3){
                      printf("-1\n");
                      return 0;
    }
    printf("%d\n%d\n",ans.first,ans.second);
    if(ans.second==1)printf("%d\n",res.first);
    else printf("%d %d\n",res.first,res.second);
  //	system("pause");
	return 0;
}