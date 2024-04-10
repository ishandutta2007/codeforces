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
string s,ans;
vector<int> ab,ba;
int main()
{
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
            if(s[i]=='A'&&s[i+1]=='B')ab.push_back(i);
            if(s[i]=='B'&&s[i+1]=='A')ba.push_back(i);
    }
    if(ab.size()<1||ba.size()<1)ans="NO";
    else if(ab.size()>2||ba.size()>2||(ba.size()==2&&ab.size()==2))ans="YES";
    else if(ab.size()==2)ans=(ab[0]+1==ba[0]&&ba[0]+1==ab[1]?"NO":"YES");
    else if(ba.size()==2)ans=(ba[0]+1==ab[0]&&ab[0]+1==ba[1]?"NO":"YES");
    else if(ab[0]==ba[0]+1||ab[0]==ba[0]-1)ans="NO";
    else ans="YES";
    cout<<ans<<endl;        
    //system("pause");
    return 0;
}