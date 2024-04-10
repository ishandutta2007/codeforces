#include<bits/stdc++.h>
using namespace std;
const int N=9999,M=9999999;
int x[N],y[N],rx1[N],rx2[N],ry[N],by1[N],by2[N],bx[N],mpx[N],mpy[N];
unordered_map<int,int>mp;
map<pair<int,int>,bool>mpp;
vector<int>vy[N],vx[N];
int he[N],to[M],len[M],ne[M],cur[N],d[N],q[N],t=1,T;
void add(int x,int y,int z){
	ne[++t]=he[x],to[t]=y,len[t]=z,he[x]=t;
	ne[++t]=he[y],to[t]=x,he[y]=t;
}
bool bfs(){
	int i,j,k,h=0,t=1;
	memset(d,0,sizeof(d)),d[0]=1,q[1]=0;
	while(h!=t){
		i=q[++h];
		for(j=he[i];j;j=ne[j])if(len[j]&&!d[k=to[j]])d[k]=d[i]+1,q[++t]=k;
	}
	return d[T];
}
int dfs(int x,int y){
	if(x==T||!y)return y;
	int &j=cur[x],k,u=0,w;
	for(;j;j=ne[j])if(len[j]&&d[k=to[j]]>d[x]){
		w=dfs(k,min(y-u,len[j])),len[j]-=w,len[j^1]+=w,u+=w;
		if(u==y)return u; 
	}
	return u;
}
int sa[N],sb[N],sd[N];
int main(){
	int n,i,j,k,lx=0,ly=0,tr=0,tb=0,l,s,la;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",x+i,y+i),mpp[{x[i],y[i]}]=1;
		if(!mp[y[i]])mp[y[i]]=++ly,mpy[ly]=y[i];
		vy[mp[y[i]]].push_back(x[i]);
	}
	for(i=1;i<=ly;++i){
		sort(vy[i].begin(),vy[i].end()),l=vy[i].size();
		for(j=1;j<l;++j)rx1[++tr]=vy[i][j-1],rx2[tr]=vy[i][j],ry[tr]=mpy[i];
	}
	for(i=1,mp.clear();i<=n;++i){
		if(!mp[x[i]])mp[x[i]]=++lx,mpx[lx]=x[i];
		vx[mp[x[i]]].push_back(y[i]);
	}
	for(i=1;i<=lx;++i){
		sort(vx[i].begin(),vx[i].end()),l=vx[i].size();
		for(j=1;j<l;++j)by1[++tb]=vx[i][j-1],by2[tb]=vx[i][j],bx[tb]=mpx[i]; 
	}
	for(i=1;i<=tr;++i)add(0,i,1);
	for(i=1,T=tr+tb+1;i<=tb;++i)add(tr+i,T,1);
	for(i=1;i<=tr;++i)for(j=1;j<=tb;++j)if(ry[i]>=by1[j]&&ry[i]<=by2[j]&&bx[j]>=rx1[i]&&bx[j]<=rx2[i]&&!mpp[{bx[j],ry[i]}])add(i,tr+j,1e9);
	while(bfs())memcpy(cur,he,sizeof(he)),dfs(0,1e9);
	for(i=1,k=s=0;i<=ly;++i){
		l=vy[i].size(),la=vy[i][0];
		for(j=1;j<l;++j)if(!d[++k])sa[++s]=mpy[i],sb[s]=la,sd[s]=vy[i][j-1],la=vy[i][j];
		sa[++s]=mpy[i],sb[s]=la,sd[s]=vy[i][j-1];
	}
	printf("%d\n",s);
	for(i=1;i<=s;++i)printf("%d %d %d %d\n",sb[i],sa[i],sd[i],sa[i]);
	for(i=1,s=0;i<=lx;++i){
		l=vx[i].size(),la=vx[i][0];
		for(j=1;j<l;++j)if(d[++k])sa[++s]=mpx[i],sb[s]=la,sd[s]=vx[i][j-1],la=vx[i][j];
		sa[++s]=mpx[i],sb[s]=la,sd[s]=vx[i][j-1];
	}
	printf("%d\n",s);
	for(i=1;i<=s;++i)printf("%d %d %d %d\n",sa[i],sb[i],sa[i],sd[i]);
	return 0;
}