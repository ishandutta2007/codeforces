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
map<string,int> m,jsq,jq,fs,cs;
int s,x,y;
string s1,s2,n[5];
inline bool cmp(int i,int j){
       string p,q;
       p=n[i],q=n[j];
       if(fs[p]!=fs[q]) return fs[p]>fs[q];
       if(jsq[p]!=jsq[q]) return jsq[p]>jsq[q];
       if(jq[p]!=jq[q]) return jq[p]>jq[q];
       return p<q;
}
       
       
       
       
       
inline void ope(){
     if(!m[s1])m[s1]=++s,n[s]=s1;
     if(!m[s2])m[s2]=++s,n[s]=s2;
     jsq[s1]+=x-y;
     jsq[s2]+=y-x;
     jq[s1]+=x;
     jq[s2]+=y;
     cs[s1]++;
     cs[s2]++;
     if(x==y)fs[s1]++,fs[s2]++;
     else fs[s1]+=3*(x>y),fs[s2]+=3*(y>x);
}

inline void tr(int i,int j){
     jsq[s1]+=i;
     jsq[s2]-=i;
     jq[s1]+=i+j;
     jq[s2]+=j;
}

inline bool ok(){
       int a[6]={0,1,2,3,4};
       sort(a+1,a+5,cmp);
       if(n[a[1]]=="BERLAND"||n[a[2]]=="BERLAND") return 1;
       return 0;
}
           
int main()
{
    for(int i=1;i<=5;i++){
            char c;
            cin>>s1>>s2>>x>>c>>y;
            ope();
    }
    for(int i=1;i<=4;i++){
            if(cs[n[i]]==2&&n[i]!="BERLAND"){
                                             s2=n[i];
                                             break;
            }
    }
    s1="BERLAND";
    fs["BERLAND"]+=3;
    for(int i=1;i<=100;i++){
            for(int j=0;j<=100;j++){
                    tr(i,j);
                    if(ok()){
                             cout<<i+j<<':'<<j<<endl;
                             //system("pause");
                             return 0;
                    }
                    tr(-i,-j);
            }
    }
    puts("IMPOSSIBLE");
    return 0;
}