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
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
ll a[5],b[5],ans=1234123412341234ll;
char c[5];
ll o(ll x,ll y,char c){return c=='+'?x+y:x*y;}
void cty(int q,int w,int e,int r){
    a[1]=b[q],a[2]=b[w],a[3]=b[e],a[4]=b[r];
    ans=min(o(o(o(a[1],a[2],c[1]),a[3],c[2]),a[4],c[3]),ans);
    ans=min(o(o(a[1],a[2],c[1]),o(a[3],a[4],c[2]),c[3]),ans);
    ans=min(o(o(a[1],a[2],c[2]),o(a[3],a[4],c[1]),c[3]),ans);
    ans=min(o(o(a[1],o(a[2],a[3],c[1]),c[2]),a[4],c[3]),ans); 
    ans=min(o(o(a[4],o(a[2],a[3],c[1]),c[2]),a[1],c[3]),ans);
    ans=min(o(a[1],o(a[2],o(a[3],a[4],c[1]),c[2]),c[3]),ans);
    a[2]=b[q],a[3]=b[w],a[4]=b[e],a[1]=b[r];
    ans=min(o(o(o(a[1],a[2],c[1]),a[3],c[2]),a[4],c[3]),ans);
    ans=min(o(o(a[1],a[2],c[1]),o(a[3],a[4],c[2]),c[3]),ans);
    ans=min(o(o(a[1],a[2],c[2]),o(a[3],a[4],c[1]),c[3]),ans);
    ans=min(o(o(a[1],o(a[2],a[3],c[1]),c[2]),a[4],c[3]),ans); 
    ans=min(o(o(a[4],o(a[2],a[3],c[1]),c[2]),a[1],c[3]),ans);
    ans=min(o(a[1],o(a[2],o(a[3],a[4],c[1]),c[2]),c[3]),ans);
    a[3]=b[q],a[4]=b[w],a[1]=b[e],a[2]=b[r];
    ans=min(o(o(o(a[1],a[2],c[1]),a[3],c[2]),a[4],c[3]),ans);
    ans=min(o(o(a[1],a[2],c[1]),o(a[3],a[4],c[2]),c[3]),ans);
    ans=min(o(o(a[1],a[2],c[2]),o(a[3],a[4],c[1]),c[3]),ans);
    ans=min(o(o(a[1],o(a[2],a[3],c[1]),c[2]),a[4],c[3]),ans);    
    ans=min(o(o(a[4],o(a[2],a[3],c[1]),c[2]),a[1],c[3]),ans);
    ans=min(o(a[1],o(a[2],o(a[3],a[4],c[1]),c[2]),c[3]),ans);
    a[4]=b[q],a[1]=b[w],a[2]=b[e],a[3]=b[r];
    ans=min(o(o(o(a[1],a[2],c[1]),a[3],c[2]),a[4],c[3]),ans);
    ans=min(o(o(a[1],a[2],c[1]),o(a[3],a[4],c[2]),c[3]),ans);
    ans=min(o(o(a[1],a[2],c[2]),o(a[3],a[4],c[1]),c[3]),ans);
    ans=min(o(o(a[1],o(a[2],a[3],c[1]),c[2]),a[4],c[3]),ans);
    ans=min(o(o(a[4],o(a[2],a[3],c[1]),c[2]),a[1],c[3]),ans);
    ans=min(o(a[1],o(a[2],o(a[3],a[4],c[1]),c[2]),c[3]),ans);
}
     
int main()
{
    ios::sync_with_stdio(0);
    cin>>b[1]>>b[2]>>b[3]>>b[4]>>c[1]>>c[2]>>c[3];
    cty(1,2,3,4),cty(1,2,4,3),cty(1,3,2,4),cty(1,3,4,2),cty(1,4,2,3),cty(1,4,3,2);
    cout<<ans<<endl;
//	system("pause");
	return 0;
}