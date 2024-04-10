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
int x,s,a[10]={0,2,3,5,7},b[20]={11,13,17,19,23,29,31,37,41,43,47};
char c[10];
int main()
{
    for(int i=1;i<=4;i++){
            printf("%d\n",a[i]);
            fflush(stdout);
            scanf("%s",c+1);
            x=(c[1]=='y'?1:0);
            s+=x;
            printf("%d\n",a[i]*a[i]);
            fflush(stdout);
            scanf("%s",c+1);
            x=(c[1]=='y'?1:0);
            s+=x;
    }
    for(int i=0;i<=10;i++){
            printf("%d\n",b[i]);
            fflush(stdout);
            scanf("%s",c+1);
            x=(c[1]=='y'?1:0);
            s+=x;
    }
    if(s<2){
            cout<<"prime\n";
            cout<<fflush;
    }
    else{
            cout<<"composite\n";
            cout<<fflush;
    } 
//	system("pause");
	return 0;
}