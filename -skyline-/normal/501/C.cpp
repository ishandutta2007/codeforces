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
int a[70000],b[70000],n,s;  
queue<int> q;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
            scanf("%d %d",a+i,b+i);
            s+=a[i];
            if(a[i]==1) q.push(i);
    }
    s/=2;
    printf("%d\n",s);
    while(!q.empty()){
                      int k=q.front();
                      q.pop();
                      if(a[k]){
                               printf("%d %d\n",k,b[k]);
                               a[k]--;
                               b[b[k]]^=k;
                               if(--a[b[k]]==1)q.push(b[k]);
                      }
    }                        
    //system("pause");
    return 0;
}