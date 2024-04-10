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
unsigned int n,p,q,ans;
vector<unsigned int> hh;
vector<unsigned int> cty(unsigned int x){
            vector<unsigned int> ans=hh;
            if(!x)ans[0]=1;
            else if(x&1){
                 vector<unsigned int> y=cty(x-1);
                 for(unsigned int i=0;i<=p;i++)ans[i]+=y[i];
                 for(unsigned int i=0;i<p;i++)ans[i+1]+=y[i];
            }
            else {
                 vector<unsigned int> y=cty(x>>1);
                 for(unsigned int i=0;i<=p;i++){
                         for(unsigned int j=0;j<=p-i;j++)ans[i+j]+=y[i]*y[j];
                 }
            }
            return ans;
}
int main()
{
    scanf("%u%u%u",&n,&p,&q); 
    for(unsigned int i=0;i<=p;i++)hh.pb(0);
    vector<unsigned int> o=cty(n);
    for(unsigned int i=1;i<=q;i++){
            unsigned int x=0,y=i;
            for(unsigned int j=0;j<=p&&j<n;j++)x+=y*o[j],y*=i;
            ans^=x;
    }
    printf("%u\n",ans);
//	system("pause");
}