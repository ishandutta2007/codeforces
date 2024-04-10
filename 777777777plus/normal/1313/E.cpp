#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;

int n,m,f[N],g1[N],g2[N];
char a[N],b[N],s[N];

void Getfail(char *s,int n){
	int a=0,p=0;
	f[0]=n;
	for(int i=1;i<n;++i){
		if(i>=p||i+f[i-a]>=p){
			p=max(p,i);
			while(p<n&&s[p]==s[p-i])p++;
			f[i]=p-i;
			a=i;
		}
		else f[i]=f[i-a];
	}
}

void Work(char *a,int *g){
	s[m]='#';
	for(int i=1;i<=n;++i)s[m+i]=a[i-1];
	Getfail(s,n+m+1);
	for(int i=1;i<=n;++i)g[i]=f[m+i];
}

struct B{
	ll a[N];
	void add(int x,ll d){
		for(;x<=m;x+=x&-x)a[x]+=d;
	}
	ll sum(int x){
		ll r=0;
		for(;x;x-=x&-x)r+=a[x];
		return r;
	}
	ll sum(int l,int r){
		return sum(r)-sum(l-1);
	}
}w[2];

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s%s",a,b,s);
	Work(a,g1);
	reverse(b,b+n);
	reverse(s,s+m);
	Work(b,g2);
	reverse(g2+1,g2+n+1);
	ll ans=0;
	for(int i=1;i<=n;++i){
		g1[i]=min(g1[i],m-1);
		g2[i]=min(g2[i],m-1);
	}
//	for(int i=1;i<=n;++i)
//	for(int j=i;j<=min(n,i+m-2);++j){
//		ans+=max(g1[i]+g2[j]-(m-1),0);
//	}
	for(int i=1,r=0;i<=n;++i){
		while(r+1<=min(n,i+m-2)){
			++r;
			if(g2[r])w[0].add(g2[r],1);
			if(g2[r])w[1].add(g2[r],g2[r]);
		}
		ans+=w[1].sum(max(m-1-g1[i],1),m);
		ans+=w[0].sum(max(m-1-g1[i],1),m)*(g1[i]-(m-1));
		if(g2[i])w[0].add(g2[i],-1);
		if(g2[i])w[1].add(g2[i],-g2[i]);
	}
	printf("%lld\n",ans);
}