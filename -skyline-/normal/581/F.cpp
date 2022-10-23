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
int n,dp[5005][2][5005],s,o[5005];
vector<int> v[5005];
void doit(int a,int b,int c,int d){
     if(dp[a][b][c]==-1) return;
     int k=dp[a][b][c];
     dp[a][b][c]=-1;
     for(int i=o[d];i>=0;i--){
             for(int j=0;j<2;j++){
                     if(dp[d][j][i]!=-1){
                                         int kk=k+dp[d][j][i]+(j^b);
                                         if(dp[a][b][c+i]==-1||dp[a][b][c+i]>kk)dp[a][b][c+i]=kk;
                     }
             }
     }
}
void ope(int k,int p){
     if(v[k].size()==1){
                        o[k]=1;
                        dp[k][0][0]=dp[k][1][1]=0;
                        return;
     }
     dp[k][0][0]=dp[k][1][0]=0;
     for(int i=0;i<v[k].size();i++){
             if(v[k][i]==p) continue;
             ope(v[k][i],k);
             for(int j=o[k];j>=0;j--){
                     doit(k,0,j,v[k][i]);
                     doit(k,1,j,v[k][i]);
             }
             o[k]+=o[v[k][i]];
     }
}
                             
int main()
{
    scanf("%d",&n);
    if(n==2){
             printf("1\n");
             return 0;
    }
    for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(v[i].size()==1)s++;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
            if(v[i].size()!=1){
                               ope(i,-1);
                               s/=2;
                               printf("%d\n",min(dp[i][0][s],dp[i][1][s]));
                               break;
            }
    }
	//system("pause");
	return 0;
}