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
//:
using namespace std;
ll n,m,k;
int main(){
    cin>>n>>m>>k;
    ++k;
    if(k<=n){
        cout<<k<<' '<<1<<endl;
        return 0;
    }
    k-=n;
    --m;
    ll r=k/(2ll*m),c=k%(2ll*m);
    if(!c){
        cout<<n+1ll-r*2ll<<' '<<2<<endl;
        return 0;
    }
    if(c<=m){
        cout<<n+1ll-(r*2ll+1ll)<<' '<<c+1ll<<endl;
        return 0;
    }
    cout<<n+1ll-(r*2ll+2ll)<<' '<<2ll*m+1ll-c+1ll<<endl;
//	system("pause");
	return 0;
}