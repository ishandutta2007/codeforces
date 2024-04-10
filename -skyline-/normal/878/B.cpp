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
int n,k,m,a[30][800005],b[1600005],c[1600005],l[30],lb,lc;
ll los[30],LOS;
pair<int,int> p[1600005];
void ope(){
     lc=0;
     LOS=0;
     int P=0;
     for(int i=1;i<=lb;i++){
             if(!P||p[P].first!=b[i])p[++P]=mp(b[i],1);
             else p[P].second++;
             if(p[P].second==k)LOS++,P--;
     }
     for(int i=1;i<=P;i++){
             for(int j=1;j<=p[i].second;j++)c[++lc]=p[i].first;
     }
}
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++)scanf("%d",a[0]+i);
    bool ok=1;
    for(int i=2;i<=n;i++)if(a[0][i]!=a[0][1])ok=0;
    if(ok){
           printf("%I64d\n",(n*1ll*m)%(k*1ll));
           return 0;
    }
    if(k>n*2){
              printf("%I64d\n",n*1ll*m);
              return 0;
    }
    lb=l[0]=n;
    for(int i=1;i<=n;i++)b[i]=a[0][i];
    ope();
    los[0]=LOS;
    l[0]=lc;
    for(int i=1;i<=lc;i++)a[0][i]=c[i];
    for(int i=0;i<29;i++){
            for(int j=1;j<=l[i];j++)b[j]=b[j+l[i]]=a[i][j];
            lb=l[i]*2;
            ope();
            los[i+1]=los[i]*2ll+LOS;
            if(lc<=n*8){
                        l[i+1]=lc;
                        for(int j=1;j<=lc;j++)a[i+1][j]=c[j];
            }
            else{
                 l[i+1]=8*n;
                 for(int j=1;j<=4*n;j++)a[i+1][j]=c[j];
                 for(int j=lc-4*n+1;j<=lc;j++)a[i+1][j-lc+8*n]=c[j];
            }
    } 
    ll lo=0;
    lc=0;
    for(int i=0;i<30;i++){
            if(((1<<i)&m)==0) continue;
            lo+=los[i];
            lb=0;
            for(int j=1;j<=lc;j++)b[++lb]=c[j];
            for(int j=1;j<=l[i];j++)b[++lb]=a[i][j];
            ope();
            lo+=LOS;
            if(lc>n*8){
                       for(int j=lc-4*n+1;j<=lc;j++)c[j-lc+8*n]=c[j];
                       lc=n*8;
            }
    }
    printf("%I64d\n",n*1ll*m-k*1ll*lo);
//	system("pause");
	return 0;
}