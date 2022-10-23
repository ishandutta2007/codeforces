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
int n,k;
int w,a[50005][12],b[50005][12],s[50005];
set<pair<int,int> >q[12];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)scanf("%d",a[1]+i),b[1][i]=a[1][i],s[1]=1;
    w=1;
    printf("1\n");
    for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++)scanf("%d",a[i]+j),b[i][j]=a[i][j],s[i]=1;
            bool ok=1;
            for(int j=1;j<=k;j++)if(a[i][j]<b[w][j])ok=0;
            if(ok){
                   for(int j=1;j<=k;j++)q[j].insert(mp(-b[w][j],w));
                   w=i;
            }
            else{
                 ok=1;
                 for(int j=1;j<=k;j++)q[j].insert(mp(-b[i][j],i));
                 while(ok){
                           ok=0;
                           for(int j=1;j<=k;j++){
                                   if(q[j].empty()) continue;
                                   if(-(q[j].begin()->first)<a[w][j]) continue;
                                   int x=q[j].begin()->second;
                                   for(int l=1;l<=k;l++)q[l].erase(mp(-b[x][l],x));
                                   for(int l=1;l<=k;l++)a[w][l]=min(a[w][l],a[x][l]),b[w][l]=max(b[w][l],b[x][l]);
                                   s[w]+=s[x]; 
                                   ok=1;
                                   break;
                           }
                 }
            }
            printf("%d\n",s[w]);
    }
//	system("pause");
	return 0;
}