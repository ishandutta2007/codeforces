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
int n,a[10];
string q="";
bool cty(int x){
     int y=(x+1)%3,z=(y+1)%3;
     if(a[x]&&!((a[y]==1&&(!a[z]))||(a[z]==1&&(!a[y])))) return 1;
     else if(a[x]) return 0;
     if(!a[y]) return 0;
     if(!a[z]) return 0;
     return 1;
}

int main()
{
    scanf("%d",&n);
    while(n--){
               char c=getchar();
               while(c<'A')c=getchar();
               if(c=='B')a[1]++;
               else if(c=='G')a[2]++;
               else a[0]++;
    }
    if(cty(1))q+='B';
    if(cty(2))q+='G';
    if(cty(0))q+='R';
    cout<<q<<endl;
//	system("pause");
	return 0;
}