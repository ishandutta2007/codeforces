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
#include<Windows.h>
using namespace std;
map<pair<int,int>,int > sy;
map<string,int> dyb;
int f,m,s,ff,mm,ss;
int main()
{
    
    dyb["rock"]=2;
    dyb["paper"]=1;
    dyb["scissors"]=0;
    sy[make_pair(0,0)]=0;
    sy[make_pair(0,1)]=1;
    sy[make_pair(0,2)]=0;
    sy[make_pair(1,0)]=0;
    sy[make_pair(1,1)]=0;
    sy[make_pair(1,2)]=1;
    sy[make_pair(2,0)]=1;
    sy[make_pair(2,1)]=0;
    sy[make_pair(2,2)]=0;
    
    string str;
    cin>>str;
    f=dyb[str];
    cin>>str;
    m=dyb[str];
    cin>>str;
    s=dyb[str];
    ff=sy[make_pair(f,m)]+sy[make_pair(f,s)];
    mm=sy[make_pair(m,f)]+sy[make_pair(m,s)];
    ss=sy[make_pair(s,m)]+sy[make_pair(s,f)];
    if(ff==2){
              cout<<'F'<<endl;
              return 0;
    }
    if(mm==2){
              cout<<'M'<<endl;
              return 0;
    }
    if(ss==2){
              cout<<'S'<<endl;
              return 0;
    }
    cout<<'?'<<endl;          
	//system("pause");
	return 0;
}