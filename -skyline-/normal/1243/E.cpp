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
int k,n[17],a[17][5005],p[33333],la[33333],C[17],P[17];
ll A,b[17];
map<ll,int> m;
void sol(int _){
    if(la[_]!=-1){
        sol(la[_]);
        sol(_^la[_]);
        return;
    }
    ll O=p[_];
    int o=m[O],la;
    while(_&(1<<o)){
        C[o]=O;
        _^=(1<<o);
        int k=m[O+b[o]];
        P[k]=o;
        O+=b[o],o=k;
    }
}
int main(){
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%d",n+i);
        for(int j=1;j<=n[i];++j){
            scanf("%d",a[i]+j);
            m[a[i][j]]=i;
            b[i]+=a[i][j];
        }
        A+=b[i];
    }
    if(A%k){
        puts("No");
        return 0;
    }
    A/=k;
    for(int i=0;i<k;++i)b[i]=A-b[i];
    for(int i=0;i<k;++i){
        for(int j=1;j<=n[i];++j){
            int _=0,o=i;
            ll O=a[i][j];
            while(1){
                if(_&(1<<o)){
                    if(O!=a[i][j])_=0;
                    break;
                }
                _|=(1<<o);
                if(!m.count(O+b[o])){
                    _=0;
                    break;
                }
                O+=b[o],o=m[O];
            }
            if(!_||la[_]) continue;
            la[_]=-1,p[_]=a[i][j];
        }
    }
    for(int _=1;_<(1<<k);++_){
        if(la[_]) continue;
        int __=_;
        do{
            if(la[__]&&la[_^__]){
                la[_]=__;
                break;
            }
            __=(__-1)&_;
        }while(__!=_);
    }
    if(!la[(1<<k)-1]){
        puts("No");
        return 0;
    }
    printf("Yes\n");
    sol((1<<k)-1);
    for(int i=0;i<k;++i)printf("%d %d\n",C[i],P[i]+1);
    //system("pause");
    return 0;
}