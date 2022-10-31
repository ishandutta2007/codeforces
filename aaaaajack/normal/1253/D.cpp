#include<bits/stdc++.h>
#define N 201000
using namespace std;
int mx[N],mn[N],f[N];
int fd(int x){
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
bool uni(int x,int y){
	int fx=fd(x),fy=fd(y);
	if(fx!=fy){
		f[fy]=fx;
		mx[fx]=max(mx[fx],mx[fy]);
		mn[fx]=min(mn[fx],mn[fy]);
		return true;
	}
	return false;
}
int main(){
	int n,m,x,y,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) f[i]=mn[i]=mx[i]=i;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		uni(x,y);
	}
	for(int i=1;i<n;i++){
		if(mx[fd(i)]>i){
			if(uni(i,i+1)) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
	
}