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
int k,n,a[30];
void cty(int x){
     if(x==n){
              if(a[n]!=k) return;
              printf("%d\n",n-1);
              for(int i=2;i<=n;i++){
                      printf("lea e%cx, [",i+96);
                      bool ok=0;
                      for(int j=1;j<i;j++){
                              if(ok) break;
                              if(a[j]*2==a[i])printf("2*e%cx]\n",j+96),ok=1;
                              if(a[j]*4==a[i])printf("4*e%cx]\n",j+96),ok=1;
                              if(a[j]*8==a[i])printf("8*e%cx]\n",j+96),ok=1;
                      }
                      for(int j=1;j<i;j++){
                              if(ok) break;
                              for(int l=1;l<i;l++){
                                      if(ok) break;
                                      for(int _=1;_<=8;_*=2){
                                              if(_*a[j]+a[l]==a[i])printf("e%cx + %d*e%cx]\n",l+96,_,j+96),ok=1;
                                      }
                              }
                      }
              }
              exit(0);
     }
     vector<int> v;
     for(int i=1;i<=x;i++)v.pb(a[i]*2),v.pb(a[i]*4),v.pb(a[i]*8);
     for(int j=1;j<=x;j++){
             for(int l=1;l<=x;l++){
                     for(int _=1;_<=8;_*=2)v.pb(_*a[j]+a[l]);
             }
     }
     sort(v.begin(),v.end()); 
     for(int i=0;i<v.size();i++){
             if(i&&v[i]==v[i-1]) continue;
             if(v[i]>a[x]&&v[i]<=k)a[x+1]=v[i],cty(x+1); 
     }
     
}                            
int main()
{
    scanf("%d",&k);
    if(k==1){
             printf("0\n");
             return 0;
    }
    a[1]=1;
    for(n=1;;n++)cty(1);
//	system("pause");
	return 0;
}