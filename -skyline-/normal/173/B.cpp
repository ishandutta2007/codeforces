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
using namespace std;
queue<int> q;
vector<int> v[2005];
int zt[2005];
int main()
{
 	int r,c;
	cin>>r>>c;
	if(r==1){
			 cout<<0<<endl;
			 return 0;
    }
	int i,j,l;
	string s;
	for(i=1;i<=r;i++){
					  cin>>s;
					  for(j=0;j<c;j++)if(s[j]=='#')v[i].push_back(j+r+1),v[j+r+1].push_back(i);
    }
    zt[r]=1;
	q.push(r);
	while(!q.empty()){
					  int tq=q.front();
					  if(tq==1){
					  			   cout<<zt[tq]-1<<endl;
					  			   //system("pause");
								   return 0;
				      }
				      q.pop();
				      for(i=0;i<(int) v[tq].size();i++)if(zt[v[tq][i]]==0)zt[v[tq][i]]=zt[tq]+1,q.push(v[tq][i]);
    }
	cout<<-1<<endl;				  
								   												 
	//system("pause");
	return 0;
}