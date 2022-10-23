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
int n,a[200][200],c[200],u[200];
string s[200];
vector<char> v;
void no(){
     cout<<"Impossible"<<endl;
     exit(0);
}

void ope(int x){
     if(u[x]==1)no();
     if(u[x]==2) return;
     u[x]=1;
     for(int i='a';i<='z';i++) if(a[x][i]) ope(i);
     u[x]=2;
     v.push_back(x);
}
     
     
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<n;i++){
            bool ok=0;
            for(int j=0;j<min(s[i].size(),s[i+1].size());j++){
                    if(s[i][j]!=s[i+1][j]){
                                           ok=1;
                                           c[s[i][j]]=c[s[i+1][j]]=1;
                                           a[s[i][j]][s[i+1][j]]=1;
                                           break;
                    }
            }
            if(!ok&&s[i].size()>s[i+1].size()) no();
    }
    for(int i='a';i<='z';i++){
            if(!u[i]&&c[i]) ope(i);
            if(!c[i]) v.push_back(i);
    }
    for(int i=v.size()-1;i>=0;i--)cout<<v[i];
    cout<<endl;                                      
   // system("pause");
    return 0;
}