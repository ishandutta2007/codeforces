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
char c[105];
int n,f[200];
vector<int> l[200];
int main()
{
    n=1,c[1]=getchar();
    while(c[n]!='\n')c[++n]=getchar();
    n--;
    for(int i=1;i<=n;i++)f[c[i]]++,l[c[i]].pb(i);
    bool ok=1;
    if(f['@']!=1)ok=0;
    if(f['/']>1) ok=0;
    for(int i=33;i<=127;i++){
            char r=i;
            if(r>='0'&&r<='9') continue;
            if(r>='a'&&r<='z') continue;
            if(r>='A'&&r<='Z') continue;
            if(r=='_'||r=='.'||r=='@'||r=='/') continue;
            if(f[i]) ok=0;
    }
    if(f['/']){
               if(n-l['/'][0]>16||n==l['/'][0])ok=0;
               n=l['/'][0]-1;
    }    
    if(!ok){
             printf("NO\n");
             return 0;
    }
    if(l['@'][0]>17||l['@'][0]==1)ok=0;
    if(n-l['@'][0]>32||n==l['@'][0])ok=0;
    if(f['.']){
    if(l['.'][0]-l['@'][0]==1||l['.'][0]-l['@'][0]>17)ok=0;
    l['.'].pb(n+1);
    for(int i=1;i<l['.'].size();i++){
            if(l['.'][i]-l['.'][i-1]==1||l['.'][i]-l['.'][i-1]>17)ok=0;
    }
    if(l['.'][0]<l['@'][0])ok=0;
    for(int i=n+1;i<=100;i++)if(c[i]=='.')ok=0;
    }
    else if(n-l['@'][0]>16||n==l['@'][0]) ok=0;
    printf(ok?"YES\n":"NO\n");
//	system("pause");
	return 0;
}