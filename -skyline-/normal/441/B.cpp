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
int n,v,a[4000],b[4000],ans;
vector<int> ve[4000];
int main()
{
    cin>>n>>v;
    int i,j,k,l=0;
    for(i=1;i<=n;i++)cin>>a[i]>>b[i],l=max(l,a[i]),ve[a[i]].push_back(i),ve[a[i]+1].push_back(i);
    for(i=1;i<=l+1;i++){
                        int vv=v;
                        for(j=0;j<ve[i].size();j++){
                                                   k=ve[i][j];
                                                   if(a[k]+1==i){
                                                                 int t=min(b[k],vv);
                                                                 b[k]-=t;
                                                                 vv-=t;
                                                   }
                        }
                        for(j=0;j<ve[i].size();j++){
                                                    k=ve[i][j];                           
                                                   if(a[k]==i){
                                                                 int t=min(b[k],vv);
                                                                 b[k]-=t;
                                                                 vv-=t;
                                                   }
                        }
                        ans+=(v-vv);                           
                                                                 
                                          
                                                                 
    }
    cout<<ans<<endl;                    
                                          
                                                        
                                                                 
	//system("pause");
	return 0;
}