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
int dtxctydtxcty,a,b,o[105][105];
int x[10005],y[10005],q,w;
int main()
{
    scanf("%d%d%d",&dtxctydtxcty,&a,&b);
    for(int i=1;i<=dtxctydtxcty;i++)(i&1)?x[++q]=i:y[++w]=i;
    for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                    if((i+j)&1){
                                if(w)o[i][j]=y[w--];
                    }
                    else if(q)o[i][j]=x[q--];
            }
    }
    if(q||w){
             printf("-1\n");
             return 0;
    }
    for(int i=1;i<=a;i++){
            for(int j=1;j<b;j++)printf("%d ",o[i][j]);
            printf("%d\n",o[i][b]);
    }
//	system("pause");
	return 0;
}