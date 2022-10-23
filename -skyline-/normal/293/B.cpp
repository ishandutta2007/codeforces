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
int moder=1000000007;
int n,m,k,a[12][12],use[12],x[40],y[40];
int u[12][12][12];

int ope(int s){
    if(s>n*m) return 1;
    int r=x[s],c=y[s],i,j,l,o,p,w=-1;
    long long g=0;
    for(i=1;i<=k;i++){
                      if((a[r][c]==0||a[r][c]==i)&&u[r][c][i]==0){
                                                                  for(j=1;j<=r;j++){
                                                                                    for(l=1;l<=c;l++)u[j][l][i]++;
                                                                  }
                                                                  for(j=r;j<=n;j++){
                                                                                    for(l=c;l<=m;l++)u[j][l][i]++;
                                                                  }
                                                                  if(a[r][c]==0)use[i]++;
                                                                  if(use[i]==1){
                                                                                //cout<<s<<endl;
                                                                                if(w==-1)w=ope(s+1);
                                                                                g+=w;
                                                                  }
                                                                  else g+=ope(s+1);
                                                                  if(a[r][c]==0)use[i]--;
                                                                  for(j=1;j<=r;j++){
                                                                                    for(l=1;l<=c;l++)u[j][l][i]--;
                                                                  }
                                                                  for(j=r;j<=n;j++){
                                                                                    for(l=c;l<=m;l++)u[j][l][i]--;
                                                                  }
                      }
    }
    int rr=g%moder;
    return rr;
}
                                                                           
                                                                  





int main()
{
    cin>>n>>m>>k;
    int i,j,l=0,o,p;
    if(n+m-1>k){
                cout<<0<<endl;
                return 0;
    }
    for(i=1;i<=n;i++){
                      for(j=1;j<=m;j++){
                                        cin>>a[i][j];
                                        use[a[i][j]]++;
                                        
                                        
                                        if(a[i][j]!=0){
                                                       int r,c;
                                                       for(r=1;r<=i;r++){
                                                                         for(c=1;c<=j;c++)u[r][c][a[i][j]]++;
                                                       }
                                                       for(r=i;r<=n;r++){
                                                                         for(c=j;c<=m;c++)u[r][c][a[i][j]]++;
                                                       }
                                                       u[i][j][a[i][j]]-=2;
                                        }
                                                                      
                                                       
                      }
                      
    
    
    }
    
    for(i=1;i<=m;i++)l++,x[l]=1,y[l]=i;
    for(j=m;j>0;j--)for(i=2;i<=n;i++)l++,x[l]=i,y[l]=j;
    
    //long long ll=ope(1);
    //ll=ll%moder;
    cout<<ope(1)<<endl;                  
                                        
   // system("pause");
    return 0;
}