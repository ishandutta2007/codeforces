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
#define X    first
#define Y    second
using namespace std;
int n,k,ans;
vector<int> res;
priority_queue<pair<int,int> >bi,sm;
int main(){
    scanf("%d%d",&n,&k);
    int l=1;
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        bi.push(mp(x,i)),sm.push(mp(-x,i));
        pair<int,int> B=bi.top(),S=sm.top();
        while(B.Y<l||S.Y<l||B.X+S.X>k){
            if(B.Y<l)bi.pop(),B=bi.top();
            else if(S.Y<l)sm.pop(),S=sm.top();
            else if(B.X==x)l=S.Y+1,sm.pop(),S=sm.top();
            else l=B.Y+1,bi.pop(),B=bi.top();
        }
        if(i-l+1>ans)ans=i-l+1,res.clear();
        if(i-l+1==ans)res.pb(i);
    }
    printf("%d %d\n",ans,res.size());
    for(int i=0;i<res.size();++i)printf("%d %d\n",res[i]-ans+1,res[i]);
//	system("pause");
	return 0;
}