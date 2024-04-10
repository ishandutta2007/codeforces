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
bool f[50][50];
vector<int> v[50],v3,v2,v1;
int main()
{
    int i,j,k,l,n,m;
    cin>>n>>m;
    for(i=1;i<=m;i++){
                      cin>>j>>k;
                      f[k][j]=1;
                      f[j][k]=1;
    }
    for(k=1;k<=n;k++){
                      for(i=1;i<=n;i++){
                                        for(j=1;j<=n;j++){
                                                          if(f[i][k]==1&&f[j][k]==1)f[i][j]=1;
                                        }
                      }
    }
                      
                                        
                                                          
    for(i=1;i<=n;i++){
                      v[i].push_back(i);
    }
    for(i=1;i<n;i++){
                      for(j=i+1;j<=n;j++){
                                          if(!f[i][j]) continue;
                                          l=v[i].size();
                                          for(k=0;k<l;k++){
                                                                     v[j].push_back(v[i][0]);
                                                                     v[i].erase(v[i].begin());
                                          }
                                           /* for(k=1;k<=n;k++){
                                                              if(v[k].size()==0)cout<<"--";
                                                              for(l=0;l<v[k].size();l++)cout<<v[k][l];
                                                              cout<<endl;
                                            }
                                            cout<<"___________________________"<<endl<<"++++++"<<endl;
                                            system("pause");*/
                    
                      }
    }
    bool fl=1;
    for(i=1;i<=n;i++){
                      if(v[i].size()>3) fl=0;
                      else if(v[i].size()==3) v3.push_back(i);
                      else if(v[i].size()==2) v2.push_back(i);
                      else if(v[i].size()==1) v1.push_back(i);
    }
    /*cout<<fl<<endl;
    cout<<v3.size()<<"    "<<v2.size()<<"    "<<v1.size()<<endl;
    system("pause");*/
    if(fl==0||(v3.size()+v2.size())>n||v2.size()>v1.size()){
                                                            cout<<-1<<endl;
                                                            //system("pause");
                                                            return 0;
    }
    for(i=0;i<v3.size();i++){
                             cout<<v[v3[i]][0]<<' '<<v[v3[i]][1]<<' '<<v[v3[i]][2]<<endl;
    }
    for(i=0;i<v2.size();i++){
                             cout<<v[v2[i]][0]<<' '<<v[v2[i]][1]<<' '<<v[v1[i]][0]<<endl;
    }
    for(i=v2.size();i<v1.size();i+=3){
                             cout<<v[v1[i]][0]<<' '<<v[v1[i+1]][0]<<' '<<v[v1[i+2]][0]<<endl;
    }           
    //system("pause");
    
    
    return 0;
}