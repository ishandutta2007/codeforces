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
string s[1005];
int n,k;
int main(){
    char c=getchar();
    while(c!=EOF){
        ++n;
        while(c!='\n')s[n]+=c,c=getchar();
        c=getchar();
        k=max(k,(int)s[n].size());
    }
    for(int i=1;i<=k+2;++i)cout<<"*";
    cout<<endl;
    int cnt=0;
    for(int i=1;i<=n;++i){
        cout<<"*";
        int o=k-s[i].size();
        if(o&1)++cnt;
        if(cnt&1){
            for(int j=1;j<=o/2;++j)cout<<" ";
            cout<<s[i];
            for(int j=1;j<=(o+1)/2;++j)cout<<" ";
        }
        else{
            for(int j=1;j<=(o+1)/2;++j)cout<<" ";
            cout<<s[i];
            for(int j=1;j<=o/2;++j)cout<<" ";
        }
        cout<<"*"<<endl;
    }
    for(int i=1;i<=k+2;++i)cout<<"*";
    cout<<endl;
//	system("pause");
	return 0;
}