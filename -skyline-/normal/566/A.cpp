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
int n,a[800005][28],k=1,ans,q[200005],p;
vector<int> v[800005];
bool b[200005];
void cty(int x,int o){
     for(int i=0;i<26;i++)if(a[x][i])cty(a[x][i],o+1);
     vector<int> r[2];
     for(int i=0;i<v[x].size();i++)if(!b[v[x][i]])r[(v[x][i]>n)].push_back(v[x][i]);
     int y=min((int)r[0].size(),(int)r[1].size());
     for(int i=0;i<y;i++){
             b[r[0][i]]=b[r[1][i]]=1;
             q[++p]=r[0][i],q[++p]=r[1][i]-n;
     }
     ans+=y*o;
}
int main()
{
    scanf("%d",&n);
    char cc=getchar();
    for(int i=1;i<=n<<1;i++){
            char c=getchar();
            int o=1;
            while(c!='\n'){                               
                           v[o].push_back(i);
                           if(!a[o][c-'a'])a[o][c-'a']=++k,o=k;
                           else o=a[o][c-'a'];
                           c=getchar();    
            }
            v[o].push_back(i);
    }
    cty(1,0); 
    printf("%d\n",ans);
    for(int i=1;i<=p;i+=2)printf("%d %d\n",q[i],q[i+1]);
	//system("pause");
	return 0;
}