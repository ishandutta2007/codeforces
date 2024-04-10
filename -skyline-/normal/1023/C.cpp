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
using namespace std;
int n,k,a[200005],o[200005],f[200005],ans[200005],s;
void go(int l,int r,int k){
    if(!k) return;
    if(k==r-l+1){
        for(int i=l;i<=r;++i)ans[i]=a[i];
        return;
    }
    if(o[l]==r){
        go(l+1,r-1,k);
        return;
    }
    if(o[l]-l+1>=k){
        go(l,o[l],k);
        return;
    }
    go(l,o[l],o[l]-l+1);
    go(o[l]+1,r,k-o[l]+l-1);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        char c;
        scanf(" %c",&c);
        if(c=='(')a[i]=1,f[++s]=i;
        else a[i]=2,o[i]=f[s],o[f[s]]=i,--s;
    }
    go(1,n,k);
    for(int i=1;i<=n;++i){
        if(ans[i]==1)printf("(");
        else if(ans[i]==2)printf(")");
    }
//	system("pause");
	return 0;
}