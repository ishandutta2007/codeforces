//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
using namespace std;
//
//
bitset<4096> b[100020];
int n,k,q,o;
pair<int,int> p[100005][13];
int main()
{
    scanf("%d%d%d",&n,&k,&q);
    o=k;
    for(int i=0;i<k;i++){
            for(int j=1;j<=n;j++){
                    int x;
                    scanf("%d",&x);
                    p[j][i]=mp(x,i);
            }
            for(int j=(1<<k)-1;j>=0;j--)b[i+1][j]=(j>>i)&1;
    }
    for(int i=1;i<=n;i++)sort(p[i],p[i]+k);
    for(int i=1;i<=q;i++){
            int t,x,y;
            scanf("%d%d%d",&t,&x,&y);
            if(t==1)b[++o]=b[x]|b[y];
            else if(t==2)b[++o]=b[x]&b[y];
            else{
                 int s=0;
                 for(int j=k-1;j>=0;j--){
                         s|=1<<p[y][j].second;
                         if(b[x][s]){
                                     printf("%d\n",p[y][j].first);
                                     break;
                         }
                 }
            }
    }
//	system("pause");                    
	return 0;
}