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
ll a[10][5];
ll di(ll i,ll j){
	ll x=a[i][1]-a[j][1],y=a[i][2]-a[j][2],z=a[i][3]-a[j][3];
	return x*x+y*y+z*z;
}
bool ok(){
	for(ll i=1;i<=8;i++){
		ll b[10]={};
		for(ll j=1;j<=8;j++){
			if(i==j) continue;
			if(j<i)b[j]=di(i,j);
			else b[j-1]=di(i,j);
		}
		sort(b+1,b+8);
		if(!b[1]||b[1]!=b[3]||b[4]!=b[6]||b[4]!=b[1]*2||b[1]*3!=b[7]) return 0;
	}
	return 1;
	
}
bool ope(ll k){
	if(k==9) return ok();
	do{
		if(ope(k+1)) return 1;
	}while(next_permutation(a[k]+1,a[k]+4));
	return 0;
}
int main()
{
	for(ll i=1;i<=8;i++){
		scanf("%I64d%I64d%I64d",a[i]+1,a[i]+2,a[i]+3);
		ll t;
		if(a[i][1]>a[i][2])t=a[i][1],a[i][1]=a[i][2],a[i][2]=t;
		if(a[i][1]>a[i][3])t=a[i][1],a[i][1]=a[i][3],a[i][3]=t;
		if(a[i][2]>a[i][3])t=a[i][2],a[i][2]=a[i][3],a[i][3]=t;
	}
	if(ope(1)){
		printf("YES\n");
		for(ll i=1;i<=8;i++)printf("%I64d %I64d %I64d\n",a[i][1],a[i][2],a[i][3]);
	}
	else printf("NO\n");
	return 0;
}