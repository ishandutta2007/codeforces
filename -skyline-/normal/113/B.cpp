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
string a,b,c;
int s,f[2000005][27];
bool u[2000005],fr[2005],en[2005];
ll ans;
int main()
{
    cin>>a;
    cin>>b;
    cin>>c;
    s=1;
    for(int i=0;i<a.size();i++)a[i]-='a';
    for(int i=0;i<b.size();i++)b[i]-='a';
    for(int i=0;i<c.size();i++)c[i]-='a';
    for(int i=0;i<a.size();i++){
            int l=i;
            bool ok=1;
            for(int j=0;j<b.size();j++,l++){
                    if(l==a.size()||a[l]!=b[j]){
                                    ok=0;
                                    break;
                    }
            }
            fr[i]=ok;
    }
    for(int i=0;i<a.size();i++){
            int l=i;
            bool ok=1;
            for(int j=0;j<c.size();j++,l++){
                    if(l==a.size()||a[l]!=c[j]){
                                    ok=0;
                                    break;
                    }
            }
            en[i]=ok;
    }
    for(int i=0;i<a.size();i++){
            if(!fr[i]) continue;     
            int t=1;
            for(int j=i;j<a.size();j++){
                    if(f[t][a[j]])t=f[t][a[j]];
                    else t=f[t][a[j]]=++s;
                    if(en[j]&&i+b.size()<=j+c.size()&&!u[t])u[t]=1,ans++;
            }
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}