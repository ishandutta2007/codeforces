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
string s,ans[44];
int k,c[444];
int main()
{
    cin>>k;
    cin>>s;
    int l=s.size();
    for(int i=1;i<=k;i++)ans[i]="";
    int t=0;
    bitset<200> b;
    for(int i=0;i<l;i++)b[s[i]]=1;
    if(b.count()<k){
                    puts("NO");
                    return 0;
    }
    for(int i=1;i<=k;i++){
            while(c[s[t]])ans[i-1]+=s[t],t++;
            c[s[t]]=1;
            ans[i]+=s[t];
            t++;
    }
    while(t!=l)ans[k]+=s[t++];
    puts("YES");
    for(int i=1;i<=k;i++)cout<<ans[i]<<endl;                                    
   // system("pause");
    return 0;
}