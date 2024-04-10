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
int n,m,k,a[3000],x,y,ans[3000],b[3000];
vector<int> v[3000];
int main()
{
    int i,j,l,f;
    cin>>n>>m;
    for(i=1;i<=n;i++){
                      cin>>a[i];
                                  
                      if(a[i]==0){k++,v[k].push_back(i),x=k;};
                      if(i==m)f=x,y=v[x].size();                  
    }
    for(i=1;i<=n;i++){
                      if(a[i]!=0){
                                              
                                  for(j=1;j<=k;j++){
                                                    l=1;
                                                    while(a[l]!=v[j][v[j].size()-1]&&l<=n)l++;
                                                    if(v[j][v[j].size()-1]==a[l]){
                                                                                  v[j].push_back(l);
                                                                                  if(l==m)f=j,y=v[j].size();
                                                    }
                                                                                  
                                  }
                      }
                      
                                        
    }/*
    for(i=1;i<=k;i++){
                      for(j=0;j<v[i].size();j++){
                                                 cout<<v[i][j]<<' ';
                      }
                      cout<<endl;
    }
     */                 
                                                 
    ans[0]=1;
    for(i=1;i<f;i++)b[i]=v[i].size();
    for(i=f;i<k;i++)b[i]=v[i+1].size();
    //cout<<'k'<<k<<endl;
    for(i=k-1;i>0;i--){
                       for(j=n;j>=b[i];j--){
                                        if(ans[j-b[i]]==1)ans[j]=1;
                       }
                       //for(j=1;j<=n;j++)cout<<ans[j];
                       //cout<<endl;
                       
    }
    for(i=0;i<=n;i++){
                      if(ans[i]==1)cout<<i+y<<endl;                   
    }                                    
    //system("pause");
    return 0;
}