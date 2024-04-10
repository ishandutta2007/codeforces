
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
map<int,string> sm;
map<string,int> ms;
int n,i,j,k,l;
pair<int,pair<int,int> >a[60],b[60],ql;
int main()
{
    scanf("%d",&n);
    string s,s1,s2;
    
    char c1[200],c2[200],ch;
    for(i=1;i<=n;i++){
                      scanf("%s",&c1);
                      s=c1;
                      sm[i]=s;
                      ms[s]=i;
    }
                      
    for(i=1;i<=n*(n-1)/2;i++){
                              cin>>s1>>k>>ch>>l;
                              s=s1.substr(0,s1.find('-'));
                              s2=s1.substr(s1.find('-')+1);
                              
                              a[ms[s]].second.first+=k;
                              a[ms[s]].second.second+=l;
                              a[ms[s2]].second.first+=l;
                              a[ms[s2]].second.second+=k;             
                              if(k>l)l=1;
                              else if(k==l)l=0;
                              else l=-1;
                              j=ms[s];
                              s=s2;
                              k=ms[s];
                              
                              if(l==0){
                                       a[j].first++,a[k].first++;
                                       continue;
                              }
                                       
                              if(l<0)swap(j,k);    
                              a[j].first+=3;
    }
    for(i=1;i<=n;i++)a[i].second.second=a[i].second.first-a[i].second.second,swap(a[i].second.first,a[i].second.second);
    for(i=1;i<=n;i++)b[i]=a[i];
    sort(b+1,b+n+1);
    l=n/2;
    k=n-l;
    string ans[40];
    for(i=k+1;i<=n;i++){
                        for(j=1;j<=n;j++){
                                          if(a[j]==b[i]){
                                                         ans[i-k]=sm[j];
                                                         a[j]=ql;
                                                         break;
                                          }
                        }
    }
    sort(ans+1,ans+l+1);
    for(i=1;i<=l;i++){
                      cout<<ans[i]<<endl;
    }                                  
    //system("pause");
    
    return 0;
}