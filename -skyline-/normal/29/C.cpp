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
map<int,vector<int> > m;
set<int> s;
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            m[x].push_back(y);
            m[y].push_back(x);
            s.insert(x);
            s.insert(y);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
                           if(m[*it].size()==1){
                                                int k=*it;
                                                s.erase(k);
                                                printf("%d ",k);
                                                k=m[k][0];
                                                while(m[k].size()==2){
                                                                      printf("%d ",k);
                                                                      s.erase(k);
                                                                      if(s.count(m[k][0]))k=m[k][0];
                                                                      else k=m[k][1];
                                                }
                                                printf("%d\n",k);
                                                break;
                           }
    }                                                     
	//system("pause");
	return 0;
}