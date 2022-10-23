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
long long res[120000];
int prev[120000],mark[120000];
set<pair<long long,int> >all;
vector<pair<int,int> >v[120000];
inline int pri(int n){
    if(n>0)pri(prev[n]);
    cout<<n+1<<' ';
}

int main()
{
    int n,m,i,j,k,l;
    cin>>n>>m;
    for(i=1;i<=m;i++){
                      int a,b,c;
                      cin>>a>>b>>c;
                      a--;
                      b--;
                      
                      v[a].push_back(make_pair(b,c));
                      v[b].push_back(make_pair(a,c));
    }
    memset(mark,0,sizeof(mark));
    mark[0]=1;
    res[0]=0;
    all.insert(make_pair(0,0));
    while(!all.empty()){
                        int it=all.begin()->second;
                        long long x=all.begin()->first;
                        all.erase(all.begin());
                        mark[it]=2;
                        for(i=0;i<v[it].size();i++){
                                                    k=v[it][i].first;
                                                    long long y=x+v[it][i].second;
                                                    if(mark[k]==0||mark[k]==1 && res[k]>y){
                                                                              if(mark[k]==1)all.erase(make_pair(res[k],k));
                                                                              mark[k]=1;
                                                                              res[k]=y;
                                                                              prev[k]=it;
                                                                              all.insert(make_pair(y,k));
                                                    }
                        }
    }
    if(mark[n-1]==2) pri(n-1);
    else  cout<<-1;
    cout<<endl;                                                        
                                                                              
	//system("pause");
	return 0;
}