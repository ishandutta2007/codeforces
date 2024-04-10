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
int n,t,s;
char s1[100005],s2[100005];
char o(int k){
     if(s1[k]!='a'&&s2[k]!='a') return 'a';
     if(s1[k]!='b'&&s2[k]!='b') return 'b';
     return 'c';
}
     
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)scanf(" %c",s1+i);
    for(int i=1;i<=n;i++)scanf(" %c",s2+i);
    for(int i=1;i<=n;i++)s+=(s1[i]!=s2[i]);
    if(t>n||t*2<s){
                   printf("-1\n");
                   return 0;
    }
    if(t<=s){
             int q=0;
             for(int i=1;i<=n;i++){
                     if(s1[i]==s2[i])printf("%c",s1[i]);
                     else if((++q)>t)printf("%c",s1[i]);
                     else if(q<=(s-t))printf("%c",s2[i]);
                     else printf("%c",o(i));
             }
             printf("\n");
    }
    else{
         t-=s;
         int q=0;
         for(int i=1;i<=n;i++){
                 if(s1[i]==s2[i]){
                                  if(++q<=t)printf("%c",o(i));
                                  else printf("%c",s1[i]);
                 }
                 else printf("%c",o(i));
         }
         printf("\n");
    }            
   // system("pause");
    return 0;
}