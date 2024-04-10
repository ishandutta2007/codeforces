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
//I prefer being hacked to being FST
using namespace std;
//
string a,b;
int x,y,f[100005],g[100005],s,k,q[100005];
int main()
{
    cin>>a>>b;
    x=a.size();
    y=b.size();
    f[0]=-1;
    for(int i=0;i<x;i++)if(a[i]==b[0])f[0]=i,i=x;
    for(int i=1;i<y;i++){
            if(f[i-1]==-1) break;
            int l=f[i-1]+1;
            while(l<x){
                       if(a[l]==b[i]) break;
                       l++;
            }
            if(l<x)f[i]=l;
            else f[i]=-1;
    }
    g[y-1]=x;
    for(int i=x-1;i>=0;i--)if(a[i]==b[y-1])g[y-1]=i,i=-1;
    for(int i=y-2;i>=0;i--){
            if(g[i+1]==x) break;
            int l=g[i+1]-1;
            while(l>=0){
                        if(a[l]==b[i]) break;
                        l--;
            }
            if(l>=0)g[i]=l;
            else g[i]=x;
    }
    int l=0;
    for(int i=0;i<y;i++){
            if(f[i]==-1) break;
            while(l<y&&(g[l]==x||g[l]<=f[i]))l++;
            if(min(i+1+y-l,y)>s)s=min(i+1+y-l,y),k=i,q[k]=max(i+1,l);
    }
    int hh=y-1;
    while(g[hh]!=x&&hh>=0)hh--;
    hh++;
    if(hh==y&&s==0)puts("-");
    else if(y-hh>s){
         for(int i=hh;i<y;i++)cout<<b[i];
         cout<<endl;
    }
    else{
         for(int i=0;i<=k;i++)cout<<b[i];
         for(int i=q[k];i<y;i++)cout<<b[i];
         cout<<endl;
    }
//	system("pause");
	return 0;
}