#include<bits/stdc++.h>
using namespace std;
const int N = 111111;
const int MO = 998244353;
int mul(int x,int y){
	return (long long)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int n,a[N],f[N],g[N];
long long s[N],p;
map<long long,int> mp;
int main(){
	int T,i,x,y,o;
	n=N-1;
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=mul(f[i-1],i);
	g[n]=fpow(f[n]);
	for(i=n;i>=1;i--)
		g[i-1]=mul(g[i],i);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			s[i]=s[i-1]+a[i];
		}
		mp.clear();
		for(i=1;i<n;i++)
			mp[s[i]]++;
		o=1;
		for(map<long long,int>::iterator it=mp.begin();it!=mp.end();it++){
			p=(*it).first;
			if(p*2<s[n]){
				x=mp[p];
				y=mp[s[n]-p];
				o=mul(o,mul(f[x+y],mul(g[x],g[y])));
			}
			if(p*2==s[n])
				o=mul(o,fpow(2,mp[p]));
		}
		printf("%d\n",o);
	}
	return 0;
}