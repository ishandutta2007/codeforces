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
string s;
int n,a[100005],b[100005];
bool f;
void cty(int o){
     int q=0;
     for(int i=1;i<=n;i++)q=q*10+a[i];
     int c[10];
     for(int i=1;i<=o;i++)c[i]=9;
     while(c[1]){
          int r=0,r2=0;
          for(int i=1;i<=o;i++)r=r*10+c[i];
          for(int i=o;i;i--)r2=r2*10+c[i];
          if(r2+r==q){
               for(int i=1;i<=o;i++)printf("%d",c[i]);
               printf("\n");
               exit(0);
          }
          r=o;
          while(c[r]==0)c[r--]=9;
          c[r]--;
     }
}
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)a[i+1]=s[i]-'0';
    int l=1,r=n;
    if(n==1){
         printf("%d\n",a[1]&1?0:a[1]>>1);
         return 0;
    }
    if(n==2){
         int t=a[1]*10+a[2];
         for(int i=99;i>=10;i--){
              if(i+i/10+(i%10)*10==t){
                   printf("%d\n",i);
                   return 0;
              }
         }
         for(int i=1;i<=9;i++){
              if(t==i<<1){
                   printf("%d\n",i);
                   return 0;
              }
         }
         printf("0\n");
         return 0;
    }
    if(n<=5){
         for(int i=n;i>=2;i--)cty(i);
         printf("0\n");
         return 0;
    }
    while(l<=r){
                if(a[l]<0) f=1;
                if(a[r]<0)a[r]+=10,a[r-1]--;
                if(l==1&&a[r]==0){
                                  if(a[1]!=1) f=1;
                                  a[r-1]--;
                                  l++;
                                  b[l]=b[r]=5;
                                  r--;
                                  if(a[2]>1)f=1;
                                  a[3]+=a[2]*10;
                                  l=3;
                                  continue;
                }
                if(l==1&&a[r]>a[l]){
                     a[r-1]--;
                     a[2]+=10;
                     int t=a[r]+10;
                     b[2]=9;
                     b[r]=t-9;
                     a[2]-=t;
                     if(a[2]<0||a[2]>1)f=1;
                     else a[3]+=a[2]*10;
                     l=3;
                     r--;
                     continue;
                }
                if(l==r){
                         if(a[l]&1) f=1;
                         else b[l]+=a[l]>>1;
                         break;
                }
                if(l+1==r){
                           int x=a[l]*10+a[r];
                           bool bb=0;
                           for(int i=0;i<=99;i++){
                                   if(i+(i/10)+(i%10)*10==x){
                                                           bb=1;
                                                           b[l]+=i/10;
                                                           b[r]+=i%10;
                                                           break;
                                   }
                           }
                           if(!bb)f=1;
                           break;
                }
                if(a[l]==a[r]){
                               if(a[l]<10)b[l]+=a[l];
                               else b[l]=9,b[r]=a[l]-9;
                }
                else{
                     if(a[l]<10){
                              if(a[l]==a[r]+1)b[l]+=a[r],a[l+1]+=10;
                              else if(a[l]==1)a[l+1]+=10,a[r-1]--,a[r]+=10,r++;
                              else f=1;
                     }
                     else{
                          b[r]+=a[l]-9,b[l]+=9;
                          if(a[l]==a[r]+10)a[r-1]--;
                          else if(a[l]==a[r]+1)a[l+1]+=10,b[r]?b[r]--:b[l]--;
                          else if(a[l]==a[r]+11)a[r-1]--,a[l+1]+=10,b[r]?b[r]--:b[l]--;
                          else f=1;
                     }
                }
                l++;
                r--;
    }
    for(int i=1;i<=n;i++)if(b[i]>9)f=1;
    if(f)printf("0\n");
    else{
         int y=1;
         while(b[y]==0)y++;
         for(int i=y;i<=n;i++)printf("%d",b[i]);
         printf("\n");
    }
  //	system("pause");                         
	return 0;
}