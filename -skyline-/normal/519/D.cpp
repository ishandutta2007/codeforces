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
//:
using namespace std;
int n;
long long f[100005],a[200],ans;
string s;
map<pair<long long,char>,int>m;
vector<int> v[200];
int main()
{
    for(int i='a';i<='z';i++)cin>>a[i];
    cin>>s;
    for(int i=0;i<s.size();i++)f[i+1]=f[i]+a[s[i]];
    n=s.size();
    s=' '+s;
    for(int i=n;i>0;i--){
            if(m.count(make_pair(f[i],s[i])))ans+=m[make_pair(f[i],s[i])];          
            if(m.count(make_pair(f[i-1],s[i])))m[make_pair(f[i-1],s[i])]++;
            else m[make_pair(f[i-1],s[i])]=1;
    }
    
    cout<<ans<<endl;        
    //system("pause");
    return 0;
}