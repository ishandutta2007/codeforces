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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
string s,t;
int n,m,q,a[100005],b[100005],x[100005],y[100005];
int main(){
    ios::sync_with_stdio(0);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    for(int i=1;i<=n;++i){
        a[i]=a[i-1]+(s[i-1]>'A');
        if(s[i-1]!='A')x[i]=i;
        else x[i]=x[i-1];
    }
    for(int i=1;i<=m;++i){
        b[i]=b[i-1]+(t[i-1]>'A');
        if(t[i-1]!='A')y[i]=i;
        else y[i]=y[i-1];
    }
    cin>>q;
    while(q--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        int k=(b[D]-b[C-1])-(a[B]-a[A-1]);
        bool ok=1;
        if(k<0||(k&1))ok=0;
        if(k==0){
            int X=B-max(A-1,x[B]),Y=D-max(C-1,y[D]);
            if(X<Y||(X-Y)%3)ok=0;
        }
        int X=B-max(A-1,x[B]),Y=D-max(C-1,y[D]);
        if(X<Y)ok=0;
        if(X==Y&&!(a[B]-a[A-1])&&(b[D]-b[C-1]))ok=0;
        if(!ok)putchar('0');
        else putchar('1');
    }
//	system("pause");
	return 0;
}