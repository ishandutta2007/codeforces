//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
using namespace std;
int n,f[25],a[500005],q,l[500005],r[500005],ans[500005];
vector<int> v[500005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    scanf("%d",&q);
    for(int i=1;i<=q;++i)scanf("%d%d",l+i,r+i),v[r[i]].pb(i);
    for(int i=1;i<=n;++i){
        int k=i;
        for(int j=19;j>=0;--j){
            if(a[k]&(1<<j)){
                if(f[j]){
                    if(f[j]<k)swap(k,f[j]);
                    a[k]^=a[f[j]];
                }
                else{f[j]=k;break;}
            }
        }
        for(int I=0;I<v[i].size();++I){
            k=v[i][I];
            for(int j=19;j>=0;--j)if(!(ans[k]&(1<<j))&&f[j]>=l[k])ans[k]^=a[f[j]];
        }
    }
    for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
//	system("pause");
	return 0;
}