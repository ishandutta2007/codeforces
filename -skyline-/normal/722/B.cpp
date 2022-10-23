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
//I prefer being hacked to being FST
using namespace std;
//
int n,p[105];
string s;
bool b;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i]; 
    getline(cin,s);
    for(int i=1;i<=n;i++){
            getline(cin,s);
            int o=0,pp=0,q=0;
            for(int j=0;j<s.size();j++){
                    if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y')o++;
            }
            /*s=s+' ';
            for(int j=0;j<s.size();j++){
                    if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y')q=1;
                    if(s[j]==' '){
                               pp+=q;
                               q=0;
                    }
            }
            if(o<p[i]||pp>p[i]) b=1; */
            if(o!=p[i]) b=1;
    }
    if(b)printf("NO\n");
    else printf("YES\n");
//	system("pause");
	return 0;
}