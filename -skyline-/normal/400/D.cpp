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
int n,m,s,a[100005],p[100005],g[100005],c[600],f[505][505];
inline int ope(int x){return x==g[x]?x:g[x]=ope(g[x]);}
int main()
{
    cin>>n>>m>>s;
    int i,j=1,k,l;
    for(i=1;i<=s;i++)cin>>c[i];
    k=c[1];
    for(i=1;i<=n;i++){
                      a[i]=j;
                      p[j]=i;
                      if(k==i)k+=c[j+1],j++;
    }
    for(i=1;i<=s;i++){
                      for(j=1;j<=s;j++)f[i][j]=100000008;
    }
                      
    for(i=1;i<=s;i++)f[i][i]=0;
    for(i=1;i<=n;i++)g[i]=i;
    for(i=1;i<=m;i++){
                      cin>>j>>k>>l;
                      f[a[j]][a[k]]=min(l,f[a[j]][a[k]]);
                      f[a[k]][a[j]]=min(l,f[a[j]][a[k]]);
                      if(l==0&&ope(j)!=ope(k)) g[ope(j)]=ope(k);
    }              
    for(i=1;i<=n;i++){
                      
                      if(ope(i)!=ope(p[a[i]])){
                                                                 
                                               cout<<"No"<<endl;
                                               return 0;
                      }
                                               
    }
    cout<<"Yes"<<endl;
    for(k=1;k<=s;k++){
                      for(i=1;i<=s;i++){
                                        for(j=1;j<=s;j++)  f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                      }
    }
    for(i=1;i<=s;i++){
                      for(j=1;j<=s;j++)cout<<(f[i][j]>100000000?-1:f[i][j])<<' ';
                      cout<<endl;
    }                  
                                                        
    
    
                      
   	//system("pause");
	return 0;
}