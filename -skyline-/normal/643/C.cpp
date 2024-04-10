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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,k,t[200005];
long double A[200005],B[200005],S[200005];
long double dp[55][200005];
int q[55][200005],ql[55],qr[55];
long double xl(int x,int y,int k){
    return ((dp[k][x]-A[x]+S[x]*B[x])-(dp[k][y]-A[y]+S[y]*B[y]))/(S[x]-S[y]);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",t+i);
    for(int i=1;i<=n;++i){
        S[i]=S[i-1]+t[i];
        A[i]=A[i-1]+S[i]/(long double)t[i];
        B[i]=B[i-1]+1.0/(long double)t[i];
    }
    for(int i=0;i<k;++i)ql[i]=1;
    qr[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=k-1;j>=0;--j){
            if(!qr[j]) continue;
            while(ql[j]<qr[j]&&xl(q[j][ql[j]],q[j][ql[j]+1],j)<=B[i])++ql[j];
            int x=q[j][ql[j]];
            dp[j+1][i]=dp[j][x]+A[i]-A[x]-S[x]*(B[i]-B[x]);
            if(j==k-1) continue;
            ++j;
            while(ql[j]<qr[j]&&xl(q[j][qr[j]-1],q[j][qr[j]],j)>xl(q[j][qr[j]],i,j))--qr[j];
            q[j][++qr[j]]=i;
            --j;
        }
    }
    printf("%.10lf\n",(double)dp[k][n]);
//	system("pause");
	return 0;
}