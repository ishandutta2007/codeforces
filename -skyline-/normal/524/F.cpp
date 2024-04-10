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
#define orz  1000000007ll
using namespace std;
int n,N,a[2000005],s[2000005],q[2000005],ql,qr,rec[1000005],ans;
int f[2000005][22];
string in;
int main(){
    ios::sync_with_stdio(0);
    cin>>in;
    n=in.size();
    for(int i=1;i<=n;++i){
        if(in[i-1]=='(')a[i]=a[i+n]=0;
        else a[i]=a[i+n]=1;
    }
    N=n*2;
    for(int i=1;i<=N;++i){
        if(a[i]==0)s[i]=s[i-1]+1;
        else s[i]=s[i-1]-1;
    }
    ql=1;
    for(int i=N;i>n;--i){
        while(qr>=ql&&s[q[qr]]>=s[i])--qr;
        q[++qr]=i;
    }
    for(int i=n;i;--i){
        while(qr>=ql&&s[q[qr]]>=s[i])--qr;
        q[++qr]=i;
        if(q[ql]==i+n)++ql;
        rec[i]=s[q[ql]]-s[i-1];
        if(s[n]<0)rec[i]-=s[n];
    }
    ll o=2;
    for(int i=1;i<=N;++i)f[i][0]=a[i];
    for(int k=0;k<20;++k){
        for(int i=1;i<=N-(2<<k)+1;++i)f[i][k+1]=(f[i][k]*o+f[i+(1<<k)][k])%orz;
        o=o*o%orz;
    }
    ans=0;
    for(int i=1;i<=n;++i){
        if(rec[i]<0) continue;
        if(!ans){
            ans=i;
            continue;
        }
        int x=ans,y=i,o=0;
        for(int k=20;k>=0;--k){
            if(o+(1<<k)>n) continue;
            if(f[x][k]==f[y][k])x+=(1<<k),y+=(1<<k),o+=(1<<k);
        }
        if(o<n&&a[y]<a[x])ans=i;
    }
    string out="";
    in+=in;
    for(int i=ans;i<=ans+n-1;++i)out+=in[i-1];
    int O=s[n];
    if(O>0){
        cout<<out;
        while(O>0)cout<<")",--O;
    }
    else{
        while(O<0)cout<<"(",++O;
        cout<<out;
    }
    cout<<endl;
//	system("pause");
	return 0;
}