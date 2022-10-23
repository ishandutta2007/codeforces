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
string s;
int res;
ll ans=1,x=3;
int main()
{
    ios::sync_with_stdio(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
            int o;
            if(s[i]=='-')o=62;
            else if(s[i]=='_')o=63;
            else if(s[i]<='9')o=s[i]-48;
            else if(s[i]<'a')o=s[i]-'A'+10;
            else o=s[i]-'a'+36;
            for(int j=0;j<6;j++)if(!(o&(1<<j)))res++;
    }
    while(res){
               if(res&1)ans=ans*x%orz;
               x=x*x%orz;
               res>>=1;
    }
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}