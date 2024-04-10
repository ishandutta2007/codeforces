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
using namespace std;
int a[105][105],x[105],y[105],k[105],zt[105];
int main()
{
	int n,i,j,l;
	cin>>l;
	n=0;
    while(l>0){
			   l--;
			   
			   int iiii;
			   cin>>iiii;
			   if(iiii==1){
				   n++;
		            i=n;
					  cin>>x[i]>>y[i];
					  for(j=1;j<i;j++){
					  					if((x[i]<x[j]&&x[j]<y[i])||(x[i]<y[j])&&(y[j]<y[i])){
																   k[j]++;
																   a[j][k[j]]=i;
									    }
										if((x[j]<x[i]&&x[i]<y[j])||(x[j]<y[i])&&(y[i]<y[j])){
																   k[i]++;
																   a[i][k[i]]=j;
									    }
				      }
               }		  
			   else
			   {
			   				  
				   int op=n;	
                   queue<int>q;  
 		           memset(zt,0,sizeof(zt));
				   int t;
				   int aa,bb;
				   cin>>aa>>bb;
	               q.push(aa);
	               t=aa;
	               zt[t]=1;
	               bool flag=0;
				   while(!q.empty()&&flag==0){
				   					 t=q.front();
									 q.pop();
									 op--;
									 for(i=1;i<=k[t];i++)if(zt[a[t][i]]==0){q.push(a[t][i]),zt[a[t][i]]=1;};
				                     if(t==bb)flag=1;
				   }
				   if(flag==0)puts("NO");else puts("YES");
			   }
	}										   
	//system("pause");
	return 0;
}