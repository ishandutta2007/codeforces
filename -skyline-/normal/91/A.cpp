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
#include<Windows.h>
using namespace std;
int i,j,k,f[130][10005],a[1000005];
string t,w,c,s;
vector<int> ti[130],wo[130];
char q,z;
int main()
{
    char sh[10005],ch[1000005];
    scanf("%s",&sh);
    t=sh;
    scanf("%s",&ch);
    w=ch;
    for(i=0;i<t.size();i++)ti[sh[i]].push_back(i);
    for(i=0;i<w.size();i++)wo[ch[i]].push_back(i);
    for(q='a';q<='z';q++){
                          if(ti[q].size()==0&&wo[q].size()>0){
                                                              printf("-1\n");
                                                              return 0;
                          }
                          if(wo[q].size()==0)ti[q].erase(ti[q].begin(),ti[q].end());
                          if(ti[q].size()==0) continue;
                          for(i=0;i<=ti[q][0];i++)f[q][i]=ti[q][0];
                          //cout<<"1234567890"<<endl;
                          for(i=1;i<ti[q].size();i++){
                                                      for(j=ti[q][i-1]+1;j<=ti[q][i];j++)f[q][j]=ti[q][i];
                          }
    }
    
    
    
    a[0]=f[ch[0]][0];
    for(i=1;i<w.size();i++){
                            if(f[ch[i]][a[i-1]+1]==0) k++,a[i]=f[ch[i]][0];
                            else a[i]=f[ch[i]][a[i-1]+1];                            
    }                      
    printf("%d\n",k+1);                                                  
    //system("pause");
    return 0;
}