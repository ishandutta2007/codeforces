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
int ans[1000005],n,c,a1[500005],a2[500005],l1,l2;
void cty(){
     int l=1;
     while(l<=l1&&l<=l2&&a1[l]==a2[l])l++;
     if(l>l1||l>l2){
                    if(l<=l1)ans[0]--;
                    return;
     }
     if(a1[l]<a2[l]){
                     ans[c-a2[l]+1]--,ans[c-a1[l]+1]++;
                     return;
     }
     ans[0]--,ans[c-a1[l]+1]++,ans[c-a2[l]+1]--;
}
int main()
{
    scanf("%d%d",&n,&c);
    scanf("%d",&l2);
    for(int i=1;i<=l2;i++)scanf("%d",a2+i);
    for(int i=1;i<n;i++){
            l1=l2;
            for(int j=1;j<=l1;j++)a1[j]=a2[j]; 
            scanf("%d",&l2);
            for(int i=1;i<=l2;i++)scanf("%d",a2+i);
            cty();
    }
    int o=-1,p=0;
    for(int i=0;i<c;i++){
            p+=ans[i];
            if(p>=0){
                     o=i;
                     break;
            }
    }
    printf("%d\n",o);       
//	system("pause");
	return 0;
}