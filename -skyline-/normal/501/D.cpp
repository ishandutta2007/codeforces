//The past is never dead, it's not even past.
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
int t[200005],lowbit[200005];
int n,ans[200005];
void add(int k,int s){
       while(k<=n){
                   t[k]+=s;
                   k+=lowbit[k];
       }        
}
int sum(int k){
       int s=0;
       while(k!=0){
                   s=s+t[k];
                   k-=lowbit[k];
       }
       return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)lowbit[i]=i&(-i);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            x++;
            ans[i]=x-1-sum(x);
            add(x,1);
    }
    memset(t,0,sizeof(t));
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            x++;
            ans[i]+=x-1-sum(x);
            add(x,1);
    }                   
    for(int i=n;i;i--){
            int x=ans[i],y=n+1-i;
            int z=x%y;
            ans[i-1]+=(x-z)/y;
            ans[i]=z;
    }                 
    memset(t,0,sizeof(t)); 
    for(int i=1;i<=n;i++){
            int l=1,r=n;
            while(r-l>1){
                         int m=(l+r)>>1;
                         if(m-1-sum(m)>=ans[i])r=m;
                         else l=m;
            }
            while(l-2-sum(l-1)>=ans[i])l--;
            while(l-1-sum(l)<ans[i])l++;
            ans[i]+=l-1-sum(l);
            if(i==n)printf("%d\n",l-1);
            else printf("%d ",l-1);
            add(l,1);
    }
            
//	system("pause");
	return 0;
}