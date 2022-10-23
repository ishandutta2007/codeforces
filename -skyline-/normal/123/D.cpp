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
string s;
int n,k,a[100005],r[200005],sa[100005],V[100005],R[100005],x[100005],y[100005],z[100005],f[100005],h[100005];
vector<int> v[100005];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;++i)r[i]=a[i]=s[i-1];
	for(int _=1;_<n;_<<=1){
		k=0;
		for(int i=1;i<=n;++i)v[r[i+_]].pb(i);
		for(int i=0;i<=100000;++i){
			for(int j=0;j<v[i].size();++j)V[++k]=v[i][j];
			v[i].clear();
		}
		k=0;
		for(int i=1;i<=n;++i)v[r[V[i]]].pb(V[i]);
		for(int i=0;i<=100000;++i){
			for(int j=0;j<v[i].size();++j)V[++k]=v[i][j];
			v[i].clear();
		}
		k=0;
		for(int i=1;i<=n;++i){
			if(i==1||mp(r[V[i]],r[V[i]+_])>mp(r[V[i-1]],r[V[i-1]+_]))++k;
			R[V[i]]=k;
		}
		for(int i=1;i<=n;++i)r[i]=R[i];
	}
	for(int i=1;i<=n;++i)sa[r[i]]=i;
	k=0;
	for(int i=1;i<=n;++i){
		if(r[i]==1){
			k=0;
			continue;
		}
		int j=sa[r[i]-1];
		if(k)--k;
		while(a[i+k]==a[j+k])++k;
		h[r[i]-1]=k;
	}
	k=0;
	ans=n*(n+1ll)/2ll;
	for(int i=1;i<=n;++i){
        int o=i;
		while(k&&x[k]>h[i])ans+=min(y[k],x[k]-h[i])*(i*1ll-z[k])*(1ll+i-z[k])/2ll,o=z[k--];
		if(x[k]<h[i])x[++k]=h[i],y[k]=h[i]-x[k-1],z[k]=o;
	}
	printf("%I64d\n",ans);
	//system("pause");
	return 0;
}