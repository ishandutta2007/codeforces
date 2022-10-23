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
int sx,sy,tx,ty;
string s;
vector<string> v;
int main(){
    cin>>s;
    sx=s[0],sy=s[1];
    cin>>s;
    tx=s[0],ty=s[1];
    while(sx!=tx||sy!=ty){
        string s="";
        if(sx<tx)s+="R",++sx;
        else if(sx>tx)s+="L",--sx;
        if(sy<ty)s+="U",++sy;
        else if(sy>ty)s+="D",--sy;
        v.pb(s);
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)cout<<v[i]<<endl;
	//system("pause");
	return 0;
}