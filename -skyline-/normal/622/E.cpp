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
#define ll   long long
//:
using namespace std;
int n,ans,q[500005],t;
vector<int> v[500005];
void cty(int k,int p,int o){
     if(v[k].size()==1)q[++t]=o;
     else{
          o++;
          for(int i=0;i<v[k].size();i++)if(v[k][i]!=p)cty(v[k][i],k,o);
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
    }
    for(int i=0;i<v[1].size();i++){
            t=0;
            cty(v[1][i],1,1);
            sort(q+1,q+t+1);
            int res=0;
            for(int i=1;i<=t;i++)res=max(res,q[i]+t-i);
            ans=max(ans,res);
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}