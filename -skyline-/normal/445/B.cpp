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
int n,m;
bool f[60],b[60][60];
void ope(int a)
{
    f[a]=1;
    for(int i=1;i<=n;i++)if(b[a][i]==1&&f[i]==0)ope(i);
}

long long fpower(long long k){
       long long ans=1,a=2;
       while(k!=0){
                   if(k%2==1)ans*=a;
                   k/=2;
                   a=a*a;
       }
       return ans;
}  
int main()
{
    int k=0,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
            cin>>x>>y;
            b[x][y]=1;
            b[y][x]=1;
    }
        
    for(int i=1;i<=n;i++)if(f[i]==0)k++,ope(i);
    cout<<fpower(n-k)<<endl;
              
  //  system("pause");
    return 0;
}