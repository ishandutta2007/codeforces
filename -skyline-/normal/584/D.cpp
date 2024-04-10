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
//:
using namespace std;
int a[2][100005];
bool p[200005];
vector<int> v;
int n;
bool prime(int x){
     if(x<200005) return !p[x];
     for(int i=0;i<v.size();i++){
             if(x%v[i]==0) return 0;
     }
     return 1;
}
int main()
{
    p[1]=1;
    for(int i=2;i<=200005;i++){
            if(p[i]) continue;
            v.push_back(i);
            for(int j=i*2;j<=200005;j+=i)p[j]=1;
    }
    for(int i=2;i<=100000;i++){
            int s=i<<1;
            for(int j=0;j<v.size();j++){
                    if(!p[s-v[j]]){
                                   a[0][i]=v[j];
                                   a[1][i]=s-v[j];
                                   break;
                    }
            }
    }
    scanf("%d",&n);
    if(prime(n)){
                 printf("1\n%d\n",n);
                 return 0;
    }
    if(prime(n-2)){
                   printf("2\n2 %d\n",n-2);
                   return 0;
    }
    for(int i=2;i<=100000;i++){
            if(prime(n-i-i)){
                             printf("3\n%d %d %d\n",n-i-i,a[0][i],a[1][i]);            
                          //   system("pause");
                             return 0;
            }
    }
    return 0;
}