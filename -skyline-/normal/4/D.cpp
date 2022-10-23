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
#include<Windows.h>
using namespace std;
struct d{
       int w,h,pw,xh,xj,dx;
};

d f[5009];

inline bool cmp(int x,int y){
       return f[x].pw>f[y].pw;
}
             
int main()
{
    int n,w,h,i,j,k,l;
    cin>>n>>w>>h;
    for(i=1;i<=n;i++){
                      cin>>j>>k;
                      if(w>=j||h>=k) j=-1,k=-1;
                      f[i].w=j;
                      f[i].h=k;
                      f[i].xh=i;
    }
    f[n+1].w=w;
    f[n+1].h=h;
    f[n+1].xh=n+1;
    for(i=1;i<=n+1;i++){
                        for(j=1;j<=n+1;j++){
                                            if(f[i].w>f[j].w&&f[i].h>f[j].h)f[i].pw++;
                        }
    }
    for(i=1;i<=n;i++){
                      for(j=i+1;j<=n+1;j++){
                                            if(cmp(i,j)) swap(f[i],f[j]);
                      }
    }

    
                                            
    
    
    
    l=1;
    while(f[l].xh!=n+1)l++;f[l].dx=0;
    for(i=l+1;i<=n+1;i++){
                          for(j=l;j<i;j++){
                                           if(f[i].w>f[j].w&&f[i].h>f[j].h&&f[i].dx<f[j].dx+1){
                                                                                               f[i].xj=j;
                                                                                               f[i].dx=f[j].dx+1;
                                           }
                          }
    }
    /*cout<<"________________________________________________________________________________"<<endl;
    for(i=1;i<=n+1;i++){
                         cout<<"w"<<f[i].w<<"h"<<f[i].h<<"dx"<<f[i].dx<<"xh"<<f[i].xh<<"xj"<<f[i].xj<<"pw"<<f[i].pw<<endl;
    }
    cout<<"________________________________________________________________________________"<<endl;
    */                    
    j=0,k=0;
    for(i=l;i<=n+1;i++){
                        if(j<f[i].dx){
                                      j=f[i].dx;
                                      k=i;
                        }
    }
    cout<<j<<endl;
    int ans[5009];
    if(j==0) return 0;
    for(i=j;i>0;i--){
                     ans[i]=f[k].xh;
                     k=f[k].xj;
    }
    for(i=1;i<j;i++){
                      cout<<ans[i]<<' ';
    }
    cout<<ans[j]<<endl;
    
                      
                     
                        
                                      
                          
                                           
                                                                                                               
                                              
   // system("pause");
    return 0;
}