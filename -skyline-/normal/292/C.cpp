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
int n,a[12],b[20],c[5],u[15];
vector<string> v;
void add(int o,int s,int k){
     if(s>k) return;
     if(o==4){
              if(k-s>2) return;
              if(k-s&&b[s]==0) return;
              if(k-s==2&&b[s]*100+b[s+1]*10+b[k]>=256) return;
              string st="";
              for(int i=1;i<=c[1];i++)st+=char(b[i]+48);
              st+='.';
              for(int i=c[1]+1;i<=c[1]+c[2];i++)st+=char(b[i]+48);
              st+='.';
              for(int i=c[1]+c[2]+1;i<s;i++)st+=char(b[i]+48);
              st+='.';
              for(int i=s;i<=k;i++)st+=char(b[i]+48);
              v.push_back(st);
              return;
     }
     c[o]=1;
     add(o+1,s+1,k);
     if(!b[s]) return;
     c[o]=2;
     add(o+1,s+2,k);
     if(b[s]*100+b[s+1]*10+b[s+2]>=256) return;
     c[o]=3;
     add(o+1,s+3,k);
}
void ope(int k){
     for(int i=1;i<=n;i++){
             b[k]=a[i];
             u[i]++;
             if(k>=2){
                      do{
                          bool f=0;  
                          for(int j=1;j<=n;j++){
                                  if(!u[j]){f=1; break;};
                          }    
                          if(f) break;
                          for(int j=1;j<=k;j++)b[k+k-j+1]=b[j];
                          add(1,1,k+k);
                          if(k!=2){
                                   for(int j=1;j<k;j++)b[k+k-j]=b[j];
                                   add(1,1,k+k-1);
                          }
                      }while(0);
             }
             if(k<6)ope(k+1);
             u[i]--;
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    ope(1);
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)cout<<v[i]<<endl;
	//system("pause");
	return 0;
}