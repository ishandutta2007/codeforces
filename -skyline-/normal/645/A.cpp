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
char a,b,c,d,e,f,g,h;
string s1="",s2="";
bool ok;
void cty(){
     char x=s2[0],y=s2[1],z=s2[2];
     s2="";
     s2+=y,s2+=z,s2+=x;
}
int main()
{
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    if(a!='X')s1+=a;
    if(b!='X')s1+=b;
    if(d!='X')s1+=d;
    if(c!='X')s1+=c;
    if(e!='X')s2+=e;
    if(f!='X')s2+=f;
    if(h!='X')s2+=h;
    if(g!='X')s2+=g;
    if(s1==s2)ok=1;
    cty();    
    if(s1==s2)ok=1;
    cty();  
    if(s1==s2)ok=1;
    printf(ok?"YES\n":"NO\n");
//	system("pause");
	return 0;
}