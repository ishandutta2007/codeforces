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
int n,k,p[3005],d[3005][3005],p0[3005],p50[3005],p100[3005],ans;
queue<int> x,y;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
            scanf("%d",p+i);
            if(p[i]==0)p0[1]++;
            else if(p[i]==100)p100[1]++;
            else p50[1]++;
    }
    if(n==1){
             printf("1\n");
             return 0;
    }
    for(int i=2;i<=n;i++){
            p0[i]=p0[i-1],p50[i]=p50[i-1],p100[i]=p100[i-1];
            if(p[i-1]==0)p0[i]--;
            else if(p[i-1]==100)p100[i]--;
            else p50[i]--;
    }
    d[1][2]=1;
    x.push(1),y.push(2);
    while(!x.empty()){
                      int a=x.front(),b=y.front();
                      x.pop(),y.pop();             
                      ans++;
                      if(b>n||d[a][b]>k) continue;
                      if(p[a]>0&&(p50[b]||p100[b])&&!d[b+1][b+2])d[b+1][b+2]=d[a][b]+1,x.push(b+1),y.push(b+2);
                      if(p[a]>0&&(!p100[b])&&!d[a][b+1])d[a][b+1]=d[a][b]+1,x.push(a),y.push(b+1);
                      if(p[a]<100&&(p50[b]||p100[b])&&!d[b][b+1])d[b][b+1]=d[a][b]+1,x.push(b),y.push(b+1);
    }
    printf("%d\n",ans);
	//system("pause");
	return 0;
}