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
int a[100005],f[5][100005][17],n,b[5][17],B[20],s,out[100005];
map<int,int> m;
vector<int> v[100005];
pair<int,int> p[1000005];
bool cty(int x,int y){
     int k=y-x;
     for(int i=0;i<5;i++){
             int X=x,Y=y;
             for(int j=0;j<=16;j++){
                     if(k&B[j]){
                                if(f[i][X][j]!=f[i][Y][j]){
                                                           return 0;
                                }
                                X+=B[j];
                                Y+=B[j];
                     }
             }
     }
     return 1;
}
int main()                              
{
    b[0][0]=31,b[1][0]=47,b[2][0]=97,b[3][0]=101,b[4][0]=orz;
    B[0]=1;
    for(int i=1;i<=16;i++)B[i]=B[i-1]*2;
    for(int i=1;i<=16;i++){
            for(int j=0;j<5;j++)b[j][i]=b[j][i-1]*b[j][i-1];
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),out[i]=a[i];
    for(int i=1;i<=n;i++){
                          for(int j=0;j<5;j++)f[j][i][0]=a[i];
    }            
    for(int k=1;k<=16;k++){
            for(int i=1;i<=n;i++){
                    if(i+B[k]-1<=n){
                                    for(int j=0;j<5;j++)f[j][i][k]=f[j][i][k-1]*b[j][k-1]+f[j][i+B[k-1]][k-1];
                    }
            }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
            if(!m[a[i]])m[a[i]]=++s;
            a[i]=m[a[i]];
            v[a[i]].pb(i);
    }
    int P=0;
    for(int i=1;i<=s;i++){
            for(int j=0;j<v[i].size();j++){
                    for(int k=j+1;k<v[i].size();k++){
                            p[++P]=mp(v[i][k]-v[i][j],v[i][j]);
                    }
            }
    }
    sort(p+1,p+P+1);
    for(int i=1;i<=P;i++){
            if(p[i].second>=ans&&cty(p[i].second,p[i].first+p[i].second))ans=p[i].first+p[i].second;
    }
    printf("%d\n",n-ans+1);
    for(int i=ans;i<n;i++)printf("%d ",out[i]);
    printf("%d\n",out[n]);
//	system("pause");
	return 0;
}