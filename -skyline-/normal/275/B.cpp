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
char a[60][60];
int x[2550],y[2550];
int main()
{
    int i,j,k=0,l=0,n,m,o;
    cin>>n>>m;
    for(i=1;i<=n;i++){
                      for(j=1;j<=m;j++){
                                        cin>>a[i][j];
                                        if(a[i][j]=='B')k++,x[k]=i,y[k]=j;
                      }
                                        
    }
    for(i=1;i<k;i++){
                      for(j=i+1;j<=k;j++){
                                          if(a[x[i]][y[j]]=='W'&&a[x[j]][y[i]]=='W')l=1;
                                          if(x[i]==x[j]){
                                                         if(y[i]>y[j]){
                                                                       for(o=y[j]+1;o<y[i];o++)if(a[x[i]][o]=='W')l=1;
                                                         }
                                                         else{
                                                                       for(o=y[i]+1;o<y[j];o++)if(a[x[i]][o]=='W')l=1;
                                                         }
                                          }
                                          if(y[i]==y[j]){
                                                         if(x[i]>x[j]){
                                                                       for(o=x[j]+1;o<x[i];o++)if(a[y[i]][o]=='W')l=1;
                                                         }
                                                         else{
                                                                       for(o=x[i]+1;o<x[j];o++)if(a[o][y[i]]=='W')l=1;
                                                         }
                                          }
                      }
                                                                                                          
    }
    cout<<(l==1?"NO":"YES")<<endl;                                    
                                                          
	//system("pause");
	return 0;
}