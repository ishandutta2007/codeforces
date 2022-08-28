#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 555555;
const int inf = 1e9;
int n,a[N],r[N],t[N],f[N],g[N];
LL s[N];
pair<LL,int> p[N];
void ad(int&x,int y){
	while(x<=n+1){
		t[x]=max(t[x],y);
		x+=x&-x;
	}
}
int qu(int x){
	int y=-inf;
	while(x){
		y=max(y,t[x]);
		x-=x&-x;
	}
	return y;
}
int main(){
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i),s[i]=s[i-1]+a[i];
		for(i=0;i<=n;i++)
			p[i+1]=make_pair(s[i],i);
		sort(p+1,p+n+2);
		x=0;
		for(i=1;i<=n+1;i++){
			if(i==1||p[i].first!=p[i-1].first)
				x++;
			r[p[i].second]=x;
			t[i]=-inf;
			g[i]=-inf;
		}
		f[0]=0;
		ad(r[0],0-0);
		for(i=1;i<=n;i++){//cout<<r[i]<<endl;
			if(a[i]<0)
				f[i]=f[i-1]-1;
			else
				f[i]=f[i-1];
			f[i]=max(f[i],qu(r[i]-1)+i);
			f[i]=max(f[i],g[r[i]]);
			ad(r[i],f[i]-i);
			g[r[i]]=max(g[r[i]],f[i]);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}