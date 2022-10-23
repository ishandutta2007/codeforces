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
//:
using namespace std;
int n,m,p1,q1,r1,p2,q2,r2,d[3005][3005];
queue<int> q;
vector<int> v[3100];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
    }
    scanf("%d%d%d%d%d%d",&p1,&q1,&r1,&p2,&q2,&r2);
    memset(d,-1,sizeof(d));
    for(int k=1;k<=n;k++){
            queue<int> q;
            q.push(k);
            d[k][k]=0;
            while(!q.empty()){
                              int t=q.front();
                              q.pop();
                              for(int i=0;i<v[t].size();i++){
                                      if(d[k][v[t][i]]!=-1) continue;
                                      d[k][v[t][i]]=d[k][t]+1;
                                      q.push(v[t][i]);
                              }
            }
    }
    if(d[p1][q1]>r1||d[p2][q2]>r2){
                                   printf("-1\n");
                                   return 0;
    }
    int ans=d[p1][q1]+d[p2][q2];
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(d[p1][i]+d[i][j]+d[j][q1]>r1||d[p2][i]+d[i][j]+d[j][q2]>r2) continue;
                    ans=min(ans,d[p1][i]+d[i][j]+d[j][q1]+d[p2][i]+d[j][q2]);
            }
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(d[p1][i]+d[i][j]+d[j][q1]>r1||d[p2][j]+d[i][j]+d[i][q2]>r2) continue;
                    ans=min(ans,d[p1][i]+d[i][j]+d[j][q1]+d[p2][j]+d[i][q2]);
            }
    }
    printf("%d\n",m-ans);                                     
   // system("pause");
    return 0;
}