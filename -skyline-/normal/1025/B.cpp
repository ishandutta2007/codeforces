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
using namespace std;
int n;
ll a[150005],b[150005],c[150005];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i];
        c[i]=a[i]*b[i]/__gcd(a[i],b[i]);
        if(i>1)c[i]=__gcd(c[i],c[i-1]);
    }
    ll ans=-1;
    vector<int> v;
    for(ll i=2;i*i<=a[1];++i){
        if(a[1]%i==0){
            v.pb(i);
            v.pb(a[1]/i);
        }
    }
    for(ll i=2;i*i<=b[1];++i){
        if(b[1]%i==0){
            v.pb(i);
            v.pb(b[1]/i);
        }
    }
    v.pb(a[1]);
    v.pb(b[1]);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        if(c[n]%v[i]==0){
            ans=v[i];
            break;
        }
    }
    if(ans>-1){
        for(int i=1;i<=n;++i){
            if((a[i]%ans)&&(b[i]%ans))ans=-1,i=n+1;
        }
    }
    cout<<ans<<endl;
//	system("pause");
	return 0;
}