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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int n,m,a[200005];
int main(){
    scanf("%d%d",&n,&m);
    if(m>=5){
        puts("YES");
        int s=0;
        if(m&1){
            for(int i=m;i>0;i-=2)a[++s]=i;
            for(int i=m-1;i>0;i-=2)a[++s]=i;
        }
        else{
            for(int i=m-1;i>0;i-=2)a[++s]=i;
            for(int i=m;i>0;i-=2)a[++s]=i;
        }
        for(int i=1;i<=m;i++)a[i+m]=a[i];
        for(int i=1;i<=n;i++){
            int o=(i-1)%m+1;
            for(int j=1;j<=m;j++)printf("%d ",a[j+o]+(i-1)*m);
            printf("\n");
        }
        return 0;
    }
    if(n>=5){
        puts("YES");
        int s=0;
        if(n&1){
            for(int i=n;i>0;i-=2)a[++s]=i;
            for(int i=n-1;i>0;i-=2)a[++s]=i;
        }
        else{
            for(int i=n-1;i>0;i-=2)a[++s]=i;
            for(int i=n;i>0;i-=2)a[++s]=i;
        }
        for(int i=1;i<=n;i++)a[i]=(a[i]-1)*m+1;
        for(int i=1;i<=n;i++)a[i+n]=a[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)printf("%d ",j-1+a[(i+j-1)%n+1]);
            printf("\n");
        }
        return 0;
    }
    if(n==1){
        if(m==1){
            puts("YES");
            puts("1");
            return 0;
        }
        if(m==2||m==3){
            puts("NO");
            return 0;
        }
        if(m==4){
            puts("YES");
            puts("3 1 4 2");
            return 0;
        }
    }
    if(n==2){
        if(m==1||m==2){
            puts("NO");
            return 0;
        }
        if(m==3){
            puts("NO");
            return 0;
        }
        if(m==4){
            puts("YES");
            puts("5 4 7 2");
            puts("3 6 1 8");
            return 0;
        }
    }
    if(n==3){
        if(m==1){
            puts("NO");
            return 0;
        }
        if(m==2){
            puts("NO");
            return 0;
        }
        if(m==3){
            puts("YES");
            puts("8 1 6");
            puts("3 5 7");
            puts("4 9 2");
            return 0;
        }
        if(m==4){
            puts("YES");
            puts("6 3 1 4");
            puts("8 10 7 2");
            puts("9 12 5 11");
            return 0;
        }
    }
    if(n==4){
        if(m==1){
            puts("YES");
            printf("3\n1\n4\n2\n");
            return 0;
        }
        if(m==2){
            puts("YES");
            puts("5 2"); 
            puts("4 7"); 
            puts("1 6"); 
            puts("8 3"); 
            return 0;
        }
        if(m==3){
            puts("YES");
            puts("3 11 5");
            puts("12 6 7");
            puts("2 8 1");
            puts("9 4 10");
            return 0;
        }
        if(m==4){
            puts("YES");
            puts("6 11 3 5");   
            puts("9 1 8 16");   
            puts("7 4 2 10");   
            puts("14 12 15 13");  
            return 0;
        } 
    }
//	system("pause");
	return 0;
}