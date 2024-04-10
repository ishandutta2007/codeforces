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
int n,a[400],f[400][400],u[400],ans[400],c[400],k;
inline void ope(int x){
       c[x]=1;
       if(!u[a[x]]) k=min(a[x],k);
       for(int i=1;i<=n;i++)if(f[x][i]&&!c[i]) ope(i);
}
       
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=n;j++)f[i][j]=s[j-1]-48;
    }
    for(int i=1;i<=n;i++){
            memset(c,0,sizeof(c));
            k=n+1;
            ope(i);
            u[k]=1;
            ans[i]=k;
    }    
    for(int i=1;i<n;i++)cout<<ans[i]<<' ';
    cout<<ans[n]<<endl;                   
	//system("pause");
	return 0;
}