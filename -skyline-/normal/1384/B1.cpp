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
int t,n,k,l,d[300005],x[300005],y[300005];
bool ins(int l,int r,int x){
    if(l<=r) return x>=l&&x<=r;
    return x>=l||x<=r;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&l);
        bool ok=1;
        for(int i=1;i<=n;++i)scanf("%d",d+i);
        x[0]=0,y[0]=2*k-1;
        for(int i=1;i<=n;++i){
            if(d[i]>l){
                ok=0;
                break;
            }
            if(d[i]+k<=l)x[i]=0,y[i]=k*2-1;
            else y[i]=l-d[i],x[i]=k*2-y[i];
            if(x[i]==k*2)x[i]=0;
            int L=x[i-1]+1,R=y[i-1]+1;
            if(L==k*2)L=0;
            if(R==k*2)R=0;
            if(ins(L,R,x[i])) continue;
            if(ins(x[i],y[i],L))x[i]=L;
            else{
                ok=0;
                break;
            }
        }
        if(ok)puts("Yes");
        else puts("No");
    }
    //system("pause");
    return 0;
}