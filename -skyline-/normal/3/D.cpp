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
using namespace std;
string s;
priority_queue<pair<int,int> > q;
ll ans;
int main(){
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='(')++cnt;
        else if(s[i]==')')--cnt;
        else if(s[i]=='?'){
            int x,y;
            scanf("%d%d",&x,&y);
            ans+=y,q.push(mp(y-x,i));
            s[i]=')',--cnt;
        }
        while(cnt<0&&!q.empty()){
            ans-=q.top().first;
            s[q.top().second]='(';
            q.pop();
            cnt+=2;
        }
        if(cnt<0){
            puts("-1");
            return 0;
        }
    }
    if(cnt!=0){
        puts("-1");
        return 0;
    }
    cout<<ans<<endl<<s<<endl;
//	system("pause");
	return 0;
}