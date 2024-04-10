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
int n,m,q,a[200],b[200],c[200],co,e[105];
bool f[105][105][105];
void ope(int v,int k){
     if(e[k]) return;
     e[k]=1;
     for(int i=1;i<=n;i++) if(f[v][i][k])ope(v,i);
}
     
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
            cin>>a[i]>>b[i]>>c[i];
            co=max(co,c[i]);
            f[c[i]][a[i]][b[i]]=f[c[i]][b[i]][a[i]]=1;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
            int u,v,s=0;
            cin>>u>>v;
            for(int j=1;j<=co;j++){
                    memset(e,0,sizeof(e));
                    ope(j,u);
                    s+=e[v];
            }
            cout<<s<<endl;
    }                    
    //system("pause");
    return 0;
}