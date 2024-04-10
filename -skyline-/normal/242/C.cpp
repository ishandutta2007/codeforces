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
//:
using namespace std;
map<pair<int,int>,int> m;
int x0,yo,x1,yl;
queue<int> qx,qy;
int main()
{                                     
    int q;
    scanf("%d%d%d%d%d",&x0,&yo,&x1,&yl,&q);
    for(int i=1;i<=q;i++){
            int k,x,y;
            scanf("%d%d%d",&k,&x,&y);
            for(int j=x;j<=y;j++)m[make_pair(k,j)]=2147483640;
    }
    if(!m.count(make_pair(x0,yo))||!m.count(make_pair(x1,yl))){
                                                               puts("-1");
                                                               return 0;
    }
    qx.push(x0);
    qy.push(yo);
    m[make_pair(x0,yo)]=0;
    while(!qx.empty()){
                       int x=qx.front(),y=qy.front(),k=m[make_pair(x,y)];
                       qx.pop(),qy.pop();
                       if(x==x1&&y==yl){
                                        printf("%d\n",k);                                                                   
                                    //    system("pause");
                                        return 0;
                       }
                       k++;
                       for(int i=-1;i<=1;i++){
                               for(int j=-1;j<=1;j++){
                                       if(m.count(make_pair(x+i,y+j))&&m[make_pair(x+i,y+j)]==2147483640){
                                                                                                          m[make_pair(x+i,y+j)]=k;
                                                                                                          qx.push(x+i);
                                                                                                          qy.push(y+j);
                                       }
                               }
                       }
    }                                                                                           
    puts("-1");         
    return 0;
}