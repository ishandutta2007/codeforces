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
int n,a[100005],k;
vector<int> v[100005];
int bit[500088];
ll ans;
int lowbit(int n){
       n=n&-n;
       return n;
} 

void add(int k,int s){
       while(k<=n*2){
                   bit[k]+=s;
                   k+=lowbit(k);
       }        
}

int sum(int k){
       int s=0;
       while(k!=0){
                   s=s+bit[k];
                   k-=lowbit(k);
       }
       return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),v[a[i]].pb(i),add(i,1),add(i+n,1);
    k=0;  
    for(int i=1;i<=100000;i++){
            for(int j=0;j<v[i].size();j++)if(v[i][j]<k)v[i][j]+=n;
            sort(v[i].begin(),v[i].end());       
            for(int j=0;j<v[i].size();j++){
                    ans+=1ll*sum(v[i][j])-sum(k);
                    add(v[i][j],-1);
                    if(v[i][j]<=n)add(v[i][j]+n,-1);
                    else add(v[i][j]-n,-1);
                    k=v[i][j];
            }
            if(k>n)k-=n;
    }
    printf("%I64d\n",ans);
//	system("pause");
	return 0;
}