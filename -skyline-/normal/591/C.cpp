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
//:
using namespace std;
int n;
bool b[500005];
vector<pair<pair<int,int>,int> > v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            b[i]=x;
    }
    b[0]=b[1];
    b[n+1]=b[n];
    b[n+2]=b[n]^1;
    int k=0;
    for(int i=1;i<=n+2;i++){
            if(b[i]!=b[k]){
                           if(i-k>1){
                                     v.push_back(make_pair(make_pair(k,i-1),b[k]));
                           }
                           k=i;
            }
    }
    if(v.size()==1){
                    printf("0\n");
                    for(int i=1;i<n;i++)printf("%d ",b[1]);
                    printf("%d\n",b[1]);
                    return 0;
    }
    int m=0;
    for(int i=1;i<v.size();i++){
            int l=v[i-1].first.second,r=v[i].first.first;
            m=max(m,(r-l)/2);
            for(int j=l+1;j<=r;j++)b[j]=v[i].second;    
            for(int j=l+1;j<=(l+r)/2;j++)b[j]=v[i-1].second;
    }
    printf("%d\n",m);
    for(int i=1;i<n;i++)printf("%d ",b[i]);
    printf("%d\n",b[n]);
  //  system("pause");
    return 0;
}