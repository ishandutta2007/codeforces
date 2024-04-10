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
int n,ok;
char c[1005][10];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++)scanf(" %c",c[i]+j);
            if(ok==1) continue;
            if(c[i][1]=='O'&&c[i][2]=='O') ok=1,c[i][1]=c[i][2]='+';
            else if(c[i][4]=='O'&&c[i][5]=='O') ok=1,c[i][4]=c[i][5]='+';
    }
    if(!ok){
            printf("NO\n");
            return 0;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++)printf("%c",c[i][j]);
            printf("\n");
    }
//	system("pause");
	return 0;
}