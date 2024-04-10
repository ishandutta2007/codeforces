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
using namespace std;
int n,a[55][55],b[55][55];
int ask(int u,int l,int d,int r){
    printf("? %d %d %d %d\n",u,l,d,r);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x^1;
}
int cha1(int x,int y){
    return a[x][y]==a[x+2][y+1]&&(a[x+1][y]==a[x+2][y]||a[x][y+1]==a[x+1][y+1]);
}
int chb1(int x,int y){
    return b[x][y]==b[x+2][y+1]&&(b[x+1][y]==b[x+2][y]||b[x][y+1]==b[x+1][y+1]);
}
int cha2(int x,int y){
    return a[x][y]==a[x+1][y+2]&&(a[x][y+1]==a[x][y+2]||a[x+1][y]==a[x+1][y+1]);
}
int chb2(int x,int y){
    return b[x][y]==b[x+1][y+2]&&(b[x][y+1]==b[x][y+2]||b[x+1][y]==b[x+1][y+1]);
}
void prta(){
    printf("!\n");
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)printf("%d",a[i][j]);
        printf("\n");
    }
    fflush(stdout);
}
void prtb(){
    printf("!\n");
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)printf("%d",b[i][j]);
        printf("\n");
    }
    fflush(stdout);
}
int main(){
    scanf("%d",&n);
    a[1][1]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i+j<=3) continue;
            if(i==n&&j==n) continue;
            if(i==1) a[i][j]=ask(i,j-2,i,j)^a[i][j-2];
            else if(j==1)a[i][j]=ask(i-2,j,i,j)^a[i-2][j];
            else a[i][j]=ask(i-1,j-1,i,j)^a[i-1][j-1];
        }
    }
    if(ask(2,1,2,3)!=(a[2][1]^a[2][3])){
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                if((i+j)&1)a[i][j]^=1;
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if((i+j)&1)b[i][j]=a[i][j]^1;
            else b[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n-2;++i){
        for(int j=1;j<=n-1;++j){
            if(cha1(i,j)!=chb1(i,j)){
                if(cha1(i,j)!=ask(i,j,i+2,j+1))prta();
                else prtb();
                return 0;
            }
        }
    }
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=n-2;++j){
            if(cha2(i,j)!=chb2(i,j)){
                if(cha2(i,j)!=ask(i,j,i+1,j+2))prta();
                else prtb();
                return 0;
            }
        }
    }
    return 0;
}