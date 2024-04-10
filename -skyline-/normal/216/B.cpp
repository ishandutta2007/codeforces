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
int n,m,a[200],s,g,f,b[200],c[200];
inline int ope(int x){return (a[x]==x?x:a[x]=ope(a[x]));}
       
inline void un(int x,int y){
       x=a[x],y=a[y];
       a[y]=x;
       b[x]+=b[y];
       c[x]+=c[y];
}
       
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=i,b[i]=1;
    for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            if(ope(x)!=ope(y))un(x,y);
            c[ope(x)]++;
    }
    for(int i=1;i<=n;i++){
            if(a[i]==i&&b[i]>1&&b[i]%2==1&&c[i]==b[i])s++;
    }
            
    if((n-s)%2==1)s++;
    cout<<s<<endl;       
	//system("pause");
	return 0;
}