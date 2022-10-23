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
int n,t,a[200005],k,f[200005];
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++){
            char c;
            scanf(" %c",&c);
            if(c=='.')k=i;
            else if(k)a[i-1]=c-'0';
            else a[i]=c-'0';
    }
    int l=n-1;
    for(int i=n-1;i>=k;i--){
            if(a[i]>4)f[i]=1;
            else if(a[i]<4)f[i]=0;
            else if(f[i+1])f[i]=f[i+1]+1;
    }
    for(int i=k;i<n;i++){
            if(f[i]<=t&&f[i]){
                        l=i-1;
                        a[l]++;
                        while(a[l]==10)a[l]=0,a[l-1]++,l--;
                        break;
            }
    }
    if(l<k){
            if(a[0])printf("%d",a[0]);
            for(int i=1;i<=l;i++)printf("%d",a[i]);
            for(int j=l+1;j<k;j++)printf("0");
            printf("\n");
    }
    else{                              
         if(a[0])printf("%d",a[0]);
         for(int i=1;i<k;i++)printf("%d",a[i]);
         printf(".");
         for(int i=k;i<=l;i++)printf("%d",a[i]);
         printf("\n");
    }
//	system("pause");
	return 0;
}