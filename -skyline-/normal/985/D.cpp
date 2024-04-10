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
#define ll   unsigned long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
//:
using namespace std;
ll n,H,o;
ll calc(ll x){
    if(x<=H) return x*(x+1ll)/2ll;
    ll res=H*(H-1ll)/2ll,Q=H+x-1ll;
    if(Q>=2828428000ll) return n;
    if(Q%2ll==1ll){
        Q=Q/2ll+1ll;
        return Q*Q-res;
    }
    Q=Q/2ll;
    return Q*(Q+1ll)-res;
}
int main(){
    cin>>n>>H;
    for(int i=30;i>=0;--i){
        ll O=o+(1ll<<i);
        if(calc(O)<n)o=O;
    }
    cout<<o+1ll<<endl;
//	system("pause");
	return 0;
}