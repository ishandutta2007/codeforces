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
//:
using namespace std;
//
//
string s,t;
int a[30],b[30],k,l;
int main()
{
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
            if(s[i]=='?')k++;
            else a[s[i]-96]++;
    }
    for(int i=0;i<t.size();i++)b[t[i]-96]++;
    for(int i=1;i<=26;i++)b[i]*=1000;
    while(1){
             int o=0;
             for(int i=1;i<=26;i++)if(a[i]<b[i])o+=b[i]-a[i];
             if(o>k) break;
             k-=o;
             for(int i=1;i<=26;i++){
                     while(a[i]<b[i]){
                                      a[i]++;
                                      while(s[l]!='?')l++;
                                      s[l]=(char)(i+96);
                     }
             }
             for(int i=1;i<=26;i++)a[i]-=b[i];
    }
    for(int i=1;i<=26;i++)b[i]/=1000;  
    while(1){
             int o=0;
             for(int i=1;i<=26;i++)if(a[i]<b[i])o+=b[i]-a[i];
             if(o>k) break;
             k-=o;
             for(int i=1;i<=26;i++){
                     while(a[i]<b[i]){
                                      a[i]++;
                                      while(s[l]!='?')l++;
                                      s[l]=(char)(i+96);
                     }
             }
             for(int i=1;i<=26;i++)a[i]-=b[i];
    }
    for(int i=0;i<s.size();i++)if(s[i]=='?')s[i]='a';
    cout<<s<<endl;
	//system("pause");
	return 0;
}