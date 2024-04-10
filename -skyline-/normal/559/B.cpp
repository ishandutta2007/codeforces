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
string x,y;
bool ok(int xl,int yl,int l){
	bool o=1;
	for(int i=0;i<l;i++)if(x[xl+i]!=y[yl+i])o=0;
	if(l&1) return o;
	if(o) return 1;
	l>>=1;
	if(ok(xl,yl+l,l)&&ok(xl+l,yl,l)) return 1;
	return (ok(xl,yl,l)&&ok(xl+l,yl+l,l));
}
int main(){
	cin>>x>>y;
	printf(ok(0,0,x.size())?"YES\n":"NO\n");
	return 0;
}