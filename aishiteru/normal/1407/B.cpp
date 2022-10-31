#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
vector<int> o;
int d,T,n,vs[N],a[N],now;
il void gcd(ct a,ct b){return !b?d=a,void():gcd(b,a%b);} 
il void dfs(ct x,ct nd){ 
	o.push_back(x),vs[x]=now;it mx=0,id=0;
	for(it i=1;i<=n;++i)
		if(vs[i]!=now){
			gcd(a[i],nd);
			if(d>mx) mx=d,id=i;
		}
	if(id) dfs(id,mx);
}
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),o.clear();it mx=0,mxi=0,mxj=0;
		for(it i=1;i<=n;++i) scanf("%d",&a[i]),mx=(a[i]>a[mx]?i:mx);
		++now,o.clear();dfs(mx,a[mx]);
		for(const int &i : o ) printf("%d ",a[i]);puts("");
	}
	return 0;
}