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
int n,k,x;
vector<int> v[100010];
bool ko;            
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
            int q;
            scanf("%d",&q);
            v[q].push_back(i);
    }
    if(v[0].size()!=1)ko=1;
    if(v[1].size()>k)ko=1;
    for(int i=2;i<n;i++)if(1ll*v[i].size()>1ll*v[i-1].size()*(k-1))ko=1;
    if(ko){
           printf("-1\n");  
           return 0;
    }
    printf("%d\n",n-1);
    for(int i=1;i<=100002;i++){
            int ls=v[i-1].size(),ss=v[i].size(),o=-1;
            for(int j=0;j<ss;j++){
                    if(j%k==0)o++;
                    printf("%d %d\n",v[i-1][o],v[i][j]);
            }
            if(i==1)k--;
    }                
	//system("pause");
	return 0;
}