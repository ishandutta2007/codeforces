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
int n,a[100005],s,f[100005],ans,o;
map<char,int> m;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            char cc;
            scanf(" %c",&cc);
            if(m[cc]) a[i]=m[cc];
            else m[cc]=++s,a[i]=s;
    }                  
    ans=n;
    int k=0;
    for(int i=1;i<=n;i++){
            while(k<n&&o<s){
                            k++;
                            if(!f[a[k]])o++;
                            f[a[k]]++;
            }
            if(o<s) break;
            ans=min(ans,k-i+1);
            if(f[a[i]]==1)o--;
            f[a[i]]--;
    }
    printf("%d\n",ans);
	//system("pause");
	return 0;
}