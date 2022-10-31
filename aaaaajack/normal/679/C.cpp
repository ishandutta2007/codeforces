#include<bits/stdc++.h>
#define N 510
using namespace std;
int cnt[N][N],isol[N][N];
char s[N][N];
int f[N*N],sz[N*N],l[N*N],r[N*N],u[N*N],d[N*N];
bool in[N*N];
int v[N*10],num;
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	l[fy]=min(l[fy],l[fx]);
	r[fy]=max(r[fy],r[fx]);
	u[fy]=max(u[fy],u[fx]);
	d[fy]=min(d[fy],d[fx]);
	sz[fy]+=sz[fx];
	f[fx]=fy;
}
int main(){
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<n;j++){
			cnt[i+1][j+1]=cnt[i+1][j]+cnt[i][j+1]-cnt[i][j];
			f[i*n+j]=i*n+j;
			if(s[i][j]=='X'){
				in[i*n+j]=true;
				cnt[i+1][j+1]++;
				continue;
			}
			sz[i*n+j]=1;
			l[i*n+j]=i;
			r[i*n+j]=i;
			u[i*n+j]=j;
			d[i*n+j]=j;
			if(i&&s[i-1][j]=='.') uni(i*n+j,(i-1)*n+j);
			if(j&&s[i][j-1]=='.') uni(i*n+j,i*n+j-1);
		}
	}
	for(int i=0;i<n*n;i++){
		if(f[i]!=i||!sz[i]) continue;
		if(r[i]-l[i]>=k||u[i]-d[i]>=k) continue;
		for(int j=max(r[i]-k+1,0);j<=l[i];j++){
			isol[j][max(u[i]-k+1,0)]+=sz[i];
			isol[j][d[i]+1]-=sz[i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			isol[i][j]+=isol[i][j-1];
		}
	}
	for(int i=0;i<=n-k;i++){
		for(int j=0;j<=n-k;j++){
			int tmp=0;
			for(int l=j;l<j+k;l++){
				if(i>0){
					int now=find((i-1)*n+l);
					if(!in[now]){
						in[now]=true;
						tmp+=sz[now];
						v[num++]=now;
					}
				}
				if(i+k<n){
					int now=find((i+k)*n+l);
					if(!in[now]){
						in[now]=true;
						tmp+=sz[now];
						v[num++]=now;
					}
				}
			}
			for(int l=i;l<i+k;l++){
				if(j>0){
					int now=find(l*n+j-1);
					if(!in[now]){
						in[now]=true;
						tmp+=sz[now];
						v[num++]=now;
					}
				}
				if(j+k<n){
					int now=find(l*n+j+k);
					if(!in[now]){
						in[now]=true;
						tmp+=sz[now];
						v[num++]=now;
					}
				}
			}
			while(num){
				in[v[--num]]=false;
			}
			tmp+=isol[i][j]+cnt[i+k][j+k]-cnt[i+k][j]-cnt[i][j+k]+cnt[i][j];
			if(tmp>ans) ans=tmp;
		}
	}
	printf("%d\n",ans);
	return 0;
}