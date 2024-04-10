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
int n,m1,m2,ans[2002];
bitset<2002> a[2002],b[2002];
void A(int x){
     ans[x]=1,ans[x^1]=2;
     for(int i=2;i<=n;i++)if(a[x][i]&&!ans[i])A(i);
}
void B(int x){
     ans[x]=1,ans[x^1]=2;
     for(int i=2;i<=n;i++)if(b[x][i]&&!ans[i])B(i);
}
int main()
{
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x<0)x=-2*x+1;
            else x=x*2;
            if(y<0)y=-2*y+1;
            else y=y*2;
            a[x^1].set(y),a[y^1].set(x);
    }
    for(int i=1;i<=m2;i++){
            int x,y;             
            scanf("%d%d",&x,&y);
            if(x<0)x=-2*x+1;
            else x=x*2;
            if(y<0)y=-2*y+1;
            else y=y*2;
            b[x^1].set(y),b[y^1].set(x);
    }
    n=n+n+1;
    for(int i=2;i<=n;i++)a[i].set(i),b[i].set(i);
    for(int i=2;i<=n;i++){
            for(int j=2;j<=n;j++){
                    if(a[j][i])a[j]|=a[i];
                    if(b[j][i])b[j]|=b[i];
            }
    }
    for(int i=2;i<=n;i++){
            if(a[i][i^1]){
                          for(int j=2;j<=n;j++)a[i].set(j),a[j].set(i^1);
            }
            if(b[i][i^1]){
                          for(int j=2;j<=n;j++)b[i].set(j),b[j].set(i^1);
            }
    }
    for(int i=2;i<=n;i++){
            for(int j=2;j<=n;j++){
                    if(a[j][i])a[j]|=a[i];
                    if(b[j][i])b[j]|=b[i];
            }
    } 
    for(int i=2;i<=n;i++){
            if(a[i]==b[i]) continue;
            for(int j=2;j<=n;j++){
                    if(a[i][j]==b[i][j]) continue;
                    if(a[i][j]){
                                j^=1;
                                B(i);
                                if(!ans[j])B(j);
                                for(int k=2;k<=n;k++){
                                        if(!ans[k])B(k);
                                }
                                for(int k=2;k<=n;k+=2){
                                        if(ans[k]==1)printf("1 ");
                                        else printf("0 ");
                                }
                                return 0;
                    } 
                    if(b[i][j]){
                                j^=1;
                                A(i);
                                if(!ans[j])A(j);
                                for(int k=2;k<=n;k++){
                                        if(!ans[k])A(k);
                                }
                                for(int k=2;k<=n;k+=2){
                                        if(ans[k]==1)printf("1 ");
                                        else printf("0 ");
                                }
                                return 0;
                    } 
            }
    }
    puts("SIMILAR");  
	//system("pause");
	return 0;
}