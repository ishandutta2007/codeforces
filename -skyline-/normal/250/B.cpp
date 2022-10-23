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
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int t,n;
string s,o[10];
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
               cin>>s;
               n=0;
               for(int i=0;i<s.size();i++)if(s[i]==':')n++;
               if(n!=7){
                        n=7-n;
                        for(int i=1;i<s.size();i++){
                                if(s[i]==':'&&s[i-1]==':'){
                                                           string x="";                  
                                                           if(n==-1)i--;
                                                           for(int j=0;j<=i;j++)x+=s[j];
                                                           for(int j=1;j<=n;j++)x+=':';
                                                           if(n==-1)i++;
                                                           for(int j=i+1;j<s.size();j++)x+=s[j];
                                                           s=x;
                                                           break;
                                }
                        }
               }
               s+=':';
               int l=0;
               n=0;
               for(int i=0;i<s.size();i++){
                       if(s[i]==':'){
                                     n++;
                                     o[n]="";
                                     for(int j=l;j<i;j++)o[n]+=s[j];
                                     l=i+1;
                                     while(o[n].size()<4)o[n]='0'+o[n];
                       }
               }
               for(int i=1;i<=7;i++)cout<<o[i]<<':';
               cout<<o[8]<<endl;
    }
//	system("pause");
	return 0;
}