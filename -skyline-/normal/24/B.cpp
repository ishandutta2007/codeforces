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

struct dri{
       string nam;
       int win[60];
       int poi;
};
       
       



map<int,string> is;
map<string,int> si;
int df[60]={0,25,18,15,12,10,8,6,4,2,1};
int n,t,sum;
dri ans[1200];

bool c1(dri x,dri y){
     if(x.poi!=y.poi) return x.poi>y.poi;
     for(int i=1;i<=50;i++)
             if(x.win[i]!=y.win[i]) return x.win[i]>y.win[i];
     return 1;
}
     
bool c2(dri x,dri y){
     if(x.win[1]!=y.win[1]) return x.win[1]>y.win[1];
     if(x.poi!=y.poi) return x.poi>y.poi;
     for(int i=2;i<=50;i++)
             if(x.win[i]!=y.win[i]) return x.win[i]>y.win[i];
     return 1;
}



int main()
{
    int i,j,k,l;
    cin>>t;
    string s;
    for(i=1;i<=t;i++){
                      cin>>n;
                      for(j=1;j<=n;j++){
                                        cin>>s;
                                        if(si[s]==0){
                                                     sum++;
                                                     si[s]=sum;
                                                     is[sum]=s;
                                                     ans[sum].nam=s;
                                                     memset(ans[sum].win,0,sizeof(ans[sum].win));
                                                     ans[sum].poi=0;
                                        }
                                        k=si[s];
                                        if(j<=10){
                                                  
                                                  ans[k].poi+=df[j];
                                        }
                                        ans[k].win[j]++;
                      }
    }
    j=1;
    for(i=1;i<=sum;i++)if(c1(ans[i],ans[j]))j=i;
    cout<<ans[j].nam<<endl;
    for(i=1;i<=sum;i++)if(c2(ans[i],ans[j]))j=i;
    cout<<ans[j].nam<<endl;                                
    //system("pause");
    return 0;
}